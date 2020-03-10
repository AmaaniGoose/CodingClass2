#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head=(struct node*)malloc(sizeof(node));
struct node *head2=head;
node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 

void list(node* temp,int n)
{
	if(n>0)
	{
		temp->link=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->link->data);
		temp->link->link=head;
		list(temp->link,n-1);
	}

}

void printall(node* temp)
{
	if(temp->link!=head)
	{
		printf("%d->",temp->data);
		printall(temp->link);
	}
	if(temp->link==head)
		printf("%d->",temp->data);

}

struct node* reverse(struct node* temp)
{
	if(temp->link==head)
	{
		head=temp;
		return temp;
	}
	struct node* curr=reverse(temp->link);
	curr->link=temp;
	temp->link=head;
	return temp; 
}
void linker(struct node* temp)
{
	if(temp->link==head)
	{
		temp->link=head2;
		head2->link=head;
		return;
	}
	linker(temp->link);
}
int main()
{
	int n,data;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	if(head==NULL)
	{
		printf("Insufficient space");
	}
	printf("Enter data of first node: ");
	scanf("%d",&data);
	head->data=data;
	head->link=NULL;
	list(head,n-1);
	printall(head);
	printf("\n");
	head=reverse(head);
	//linker(head);
	printall(head);
	return 0;
}
