#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head,*loc,*last;

node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 

void list(int n, int choice)
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
last=temp;
loc=head;
if(choice==0)
{	
	printf("Creating singly linked list whose last pointer points towards NULL");
	last->link=NULL;
	return;
}
for(i=0;i<choice-1;i++)
{
	loc=loc->link;
}
printf("Now linking with: %d and location %d ",loc->data,choice);
last->link=loc;

}

void linkfinder()
{
	int count=1;
	int length=1;
	struct node *temp,*temp2;
	temp=head;
	temp2=head;
	while(temp->link!=last)
	{	
		length++;
		temp=temp->link;
	}
	if(temp->link==NULL)
	{
		printf("Its a singly linked list ");
		return;
	}
	while(temp2->link!=last->link)
	{
		count++;
		temp2=temp2->link;
	}
	temp2=temp2->link;
	if(count>length)
	{
		count=count-length-1;
	}
	printf("The link is at location %d with data value %d",count+1,temp2->data);
}

void printall()
{
	struct node* temp;
	temp=loc;
	while(temp->link!=loc)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d->",temp->data);
}
int main()
{
	int n,choice;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter the choice: 0 for NULL ");
	scanf("%d",&choice);
	list(n,choice);
	printf("\n");
	printall();
	printf("\n");
	linkfinder();
	
}
