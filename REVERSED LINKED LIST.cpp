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
void printall(struct node *head)
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
}
struct node *reverse(struct node *head)
{	
	if(head==NULL || head->link==NULL)
	{
		return head;
	}
	struct node *revhead;
	revhead=reverse(head->link);
	head->link->link=head;
	head->link=NULL;
	
	return revhead;
	
}
int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	list(n);
	printall(head);
	head=reverse(head);
	printf("\n");
	printall(head);

}
