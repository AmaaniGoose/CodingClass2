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
	newNode->back=last;
	last->fwd=newnode;
	last=newnode;
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
		temp=temp->fwd;
	}
}
int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	list(n);
	printall();
}
