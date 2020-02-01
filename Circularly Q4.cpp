#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head;

node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 

void list(int n)
{
struct node *temp,*newnode;
int i,data,count=0;
head=(struct node*)malloc(sizeof(node));
if(head==NULL)
{
	printf("Insufficient space");
}
printf("Enter data of first node: ");
scanf("%d",&data);
head->data=data;
head->link=NULL;
temp=head;
count++;
for(i=0;i<n-1;i++)
{
	printf("Enter data for node %d: ",count+1);
	scanf("%d",&data);
	newnode=getnode(data);
	temp->link=newnode;
	newnode->link=head;
	temp=newnode;
	count++;
}
}
void printall()
{	printf("Current list is: ");
	struct node* temp;
	temp=head;
	while(temp->link!=head)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d",temp->data);
}

void printallspecial()
{
	struct node* temp;
	temp=head;
	int count=1;
	while(temp->link!=head)
	{
		printf("%d{%d}->",temp->data,count);
		temp=temp->link;
		count++;
	}
}

void insertbeg()
{
	struct node *newnode,*temp;
	int data;
	printf("Enter data for new node : ");
	scanf("%d",&data);
	newnode=getnode(data);
	temp=head;
	while(temp->link!=head)
	{	
		temp=temp->link;
	}
	temp->link=newnode;
	newnode->link=head;
	head=newnode;
}

void insertend()
{
	struct node *newnode;
	int data;
	printf("Enter data for new node : ");
	scanf("%d",&data);
	newnode=getnode(data);
	struct node* temp;
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=newnode;
	newnode->link=head;	
	
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
	
	printf(" \nMenu for operations: Enter 1 for insertion at beginning and 2 for insertion at end: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: insertbeg();
				printall();
		
		break;
		
		case 2: insertend();
				printall();
		
		break;
		
		/*case 3: insertmid();
				printall();*/
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	return 0;
}
