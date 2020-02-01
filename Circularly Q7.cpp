#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head,*head2;

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
head=(struct node*)malloc(sizeof(struct node));
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
void split(int n)
{
	int i;
	struct node *temp,*temp3;
	temp=head;
	temp3=head;
	while(temp3->link!=head)
	{
		temp3=temp3->link;
	}
	head2=(struct node*)malloc(sizeof(struct node));
	if(n%2==0)
	{
		for(i=1;i<n/2;i++)
		{
			temp=temp->link;
		}
		head2=temp->link;
		temp->link=head;
		temp3->link=head2;
	}
	else
	{
		for(i=1;i<(n+1)/2;i++)
		{
			temp=temp->link;
		}
		head2=temp->link;
		temp->link=head;
		temp3->link=head2;
	}
}
void printall(struct node *head)
{
	struct node* temp;
	temp=head;
	while(temp->link!=head)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d->",temp->data);
}
int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	list(n);
	printall(head);
	split(n);
	printf("\n Now printing splitted lists \n");
	printall(head);
	printf("\n");
	printall(head2);
}
