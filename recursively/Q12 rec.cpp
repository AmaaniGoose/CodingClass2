#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *fwd;
	struct node *back;
};
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->fwd = NULL; 
    newNode->back=NULL;
    return newNode; 
} 
void print(struct node*temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		print(temp->fwd);
	}
}

void create(struct node*temp,int n)
{
	if(n>0)
	{
		temp->fwd=(struct node*)malloc(sizeof(struct node));
		printf("enter data : ");
		scanf("%d",&temp->fwd->data);
		temp->fwd->back=temp;
		temp->fwd->fwd=NULL;
		create(temp->fwd,n-1);
	}
}
void insertbeg()
{
	struct node *newnode;
	int data;
	printf("Enter data for new node : ");
	scanf("%d",&data);
	newnode=getnode(data);
	newnode->fwd=head;
	head->back=newnode;
	head=newnode;
	
}

void insertend(struct node* temp)
{
	if(temp->fwd==NULL)
	{
		struct node *newnode;
		int data;
		printf("Enter data for new node : ");
		scanf("%d",&data);
		newnode=getnode(data);
		temp->fwd=newnode;
		newnode->back=temp;
		return;
	}
	insertend(temp->fwd);
}

void insertmid(struct node* temp, int loc)
{
	if(loc==0)
	{
		struct node *newnode,*temp2;
		temp2=temp->fwd;
		int data;
		printf("Enter data for new node : ");
		scanf("%d",&data);
		newnode=getnode(data);
		temp->fwd=newnode;
		newnode->back=temp;
		newnode->fwd=temp2;
		temp2->back=newnode;
		return;
	}
	insertmid(temp->fwd,loc-1);
}
int main()
{
	int i,j,n,data,loc;
	printf("enter no. of nodes you want: ");
	scanf("%d",&n);
	struct node *temp;
	temp=head;
	printf("enter data : ");
	scanf("%d",&head->data);
	head->back=NULL;
	head->fwd=NULL;
	create(temp,n-1);
	printf("printing the data :");
	temp=head;
	print(temp);
	int ch;
	int ch1=1;
	while(ch1==1)
	{
	
	printf(" \nMenu for operations: Enter 1 for insertion at beginning and 2 for insertion at end and 3 for insertion at desired spot: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: insertbeg();
				print(head);
				n++;
		
		break;
		
		case 2:	insertend(head);
				print(head);
				n++;
		
		break;
		
		case 3: printf("Enter location: ");
				scanf("%d",&loc);
				insertmid(head,loc-1);
				print(head);
				n++;
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	return 0;	
}
