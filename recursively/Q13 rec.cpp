#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *fwd;
		 struct node *back;	  	
	 };
struct node *head=(struct node*)malloc(sizeof(struct node));

node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
  	newNode->back=NULL;
    newNode->fwd = NULL; 
    return newNode; 
} 


void list(struct node* head,int n)
{
if(n>0)
{
	head->fwd=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&head->fwd->data);
	head->fwd->back=head;
	head->fwd->fwd=NULL;
	list(head->fwd,n-1);
}
}
void printall(struct node* head)
{	
if(head!=NULL)
{
	printf("%d->",head->data);
	printall(head->fwd);
}

}
void deletebeg()
{
	struct node* temp;
	temp=head;
	temp=temp->fwd;
	free(head);
	head=temp;
	head->back=NULL;
	
}

void deleteend(struct node* head)
{
	if(head->fwd->fwd==NULL)
	{
		struct node* temp;
		temp=head->fwd;
		head->fwd=NULL;
		free(temp);
		return;	
	}
	deleteend(head->fwd);
}

void deletemid(struct node* temp, int loc)
{
	if(loc==0)
	{
		struct node* temp2=temp->fwd;
		temp->fwd->fwd->back=temp;
		temp->fwd=temp->fwd->fwd;
		free(temp2);
		return;
	}
	deletemid(temp->fwd,loc-1);
}
int main()
{
	int n,data,loc;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	if(head==NULL)
	{
		printf("Insufficient space");
	}
	printf("Enter data of first node: ");
	scanf("%d",&data);
	head->data=data;
	head->fwd=NULL;
	head->back=NULL;
	list(head,n-1);
	printall(head);
	int ch;
	int ch1=1;
	while(ch1==1)
	{
	printf(" \nMenu for operations: Enter 1 for deletion at beginning and 2 for deletion at end and 3 for deletion at desired spot: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: deletebeg();
				printall(head);
		
		break;
		
		case 2: deleteend(head);
				printall(head);
		
		break;
		
		case 3: printf("Enter location: ");
				scanf("%d",&loc);
				deletemid(head,loc-1);
				printall(head);
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	
	return 0;
}
