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
	temp=temp->link;
	count++;
}
}
void printall()
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
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
		temp=temp->link;
		count++;
	}
}
void nthnode(int size, int n)
{
	struct node *temp;
	int count=1;
	temp=head;
	while(count!=size-n+1)
	{
		temp=temp->link;
		count++;
	}
	printf("%d",temp->data);
}
int main()
{
	int n,n2;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	list(n);
	printallspecial();
	printf("\n Enter the value of n: ");
	scanf("%d",&n2);
	nthnode(n,n2);

}
