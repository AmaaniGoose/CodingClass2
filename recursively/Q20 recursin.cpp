#include<stdio.h>
#include<stdlib.h>
typedef struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head=(struct node*)malloc(sizeof(node));
struct node *head2=(struct node*)malloc(sizeof(node));
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

void printall(node* temp,node* head)
{
	if(temp->link!=head)
	{
		printf("%d->",temp->data);
		printall(temp->link,head);
	}
	if(temp->link==head)
		printf("%d->",temp->data);

}


void split(struct node* temp,int n)
{	
	static int half;
	static struct node* temp3=head;
	if(n%2==0)
	{
		half=n/2;
	}
	else
	{
		half=(n+1)/2;
	}
	while(temp3->link!=head)
	{
		temp3=temp3->link;
	}
	if(n%2==0)
	{
		if(n==0)
		{
			head2=temp->link;
			temp->link=head;
			temp3->link=head2;
			return;
		}
		split(temp->link,(n/2)-1);
	}
	else
	{
		if(n==0)
		{
			head2=temp->link;
			temp->link=head;
			temp3->link=head2;
			return;
		}
		split(temp->link,((n+1)/2)-1);
	}
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
	printall(head,head);
	split(head,n);
	printf("\n");
	printall(head,head);
	printf("\n");
	printall(head2,head2);
	return 0;
}
