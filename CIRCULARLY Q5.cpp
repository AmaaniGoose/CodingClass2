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
	if(head==NULL)
	{printf("Empty LIST ");
	}
	temp=head;
	while(temp->link!=head)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d",temp->data);
}
/*
void printallspecial()
{
	struct node* temp;
	temp=head;
	int count=1;
	while(temp!=NULL)
	{
		printf("%d{%d}->",temp->data,count);
		temp=temp->link;
		count++;
	}
}*/

void deletebeg()
{
	struct node *temp,*temp2;
	temp=head;
	temp2=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=head->link;
	free(temp2);
	head=temp->link;
	
}

void deleteend()
{
	struct node *temp,*temp2;
	temp=head;
	while(temp->link->link!=head)
	{
		temp=temp->link;
	}
	temp2=temp->link;
	temp->link=head;
	free(temp2);
	
	
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
	printf(" \nMenu for operations: Enter 1 for deletion at beginning and 2 for deletion at end: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: deletebeg();
				printall();
		
		break;
		
		case 2: deleteend();
				printall();
		
		break;
		
		/*case 3: deletemid();
				printall();*/
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	
	return 0;
}
