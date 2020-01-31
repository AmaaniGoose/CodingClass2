#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *fwd;
		 struct node *back;	  	
	 };
struct node *head;
struct node *last;

node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
  	newNode->back=NULL;
    newNode->fwd = NULL; 
    return newNode; 
} 


void list(int n)
{
struct node *newnode;
int i,data,count=0;
head=(struct node*)malloc(sizeof(node));
if(head==NULL)
{
	printf("Insufficient space");
}
printf("Enter data of first node: ");
scanf("%d",&data);
head->data=data;
head->fwd=NULL;
head->back=NULL;
last=head;
count++;
for(i=0;i<n-1;i++)
{
	printf("Enter data for node %d: ",count+1);
	scanf("%d",&data);
	newnode=getnode(data);
	newnode->back=last;
	last->fwd=newnode;
	last=newnode;
	count++;
}

}
void printall()
{	printf("Current list is: ");
	struct node* temp;
	if(head==NULL)
	{printf("Empty LIST ");
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->fwd;
	}
}

void printallspecial()
{
	struct node* temp;
	temp=head;
	int count=1;
	while(temp!=NULL)
	{
		printf("%d{%d}->",temp->data,count);
		temp=temp->fwd;
		count++;
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

void deleteend()
{
	struct node *temp;
	temp=last->back;
	delete(last);
	last=temp;
	last->fwd=NULL;
}

void deletemid()
{	
	struct node *temp,*temp2,*newnode;
	int data;
	printf("This is the given linked list ");
	printallspecial();
	int choice;
	printf("Enter location to delete the newnode: ");
	scanf("%d",&choice);
	int count=1;
	temp=head;
	while(count!=choice)
	{
		temp=temp->fwd;
		count++;
	}
	if(temp->fwd==NULL)
	{
		deleteend();
		return;
	}
	printf("The new data will be deleted after %d which holds value %d \n",count,temp->data);
	temp2=temp->fwd->fwd;
	free(temp->fwd);
	temp->fwd=temp2;
	temp2->back=temp;
	}
int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	list(n);
	printall();
	int ch;
	int ch1=1;
	while(ch1==1)
	{
	printf(" \nMenu for operations: Enter 1 for deletion at beginning and 2 for deletion at end and 3 for deletion at desired spot: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: deletebeg();
				printall();
		
		break;
		
		case 2: deleteend();
				printall();
		
		break;
		
		case 3: deletemid();
				printall();
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	
	return 0;
}
