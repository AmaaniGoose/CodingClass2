#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head1,*head2;

node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 

void list1(int n)
{
struct node *temp,*newnode;
int i,data,count=0;
head1=(struct node*)malloc(sizeof(node));
if(head1==NULL)
{
	printf("Insufficient space");
}
printf("Enter data of first node: ");
scanf("%d",&data);
head1->data=data;
head1->link=NULL;
temp=head1;
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

void list2(int n)
{
struct node *temp,*newnode;
int i,data,count=0;
head2=(struct node*)malloc(sizeof(node));
if(head2==NULL)
{
	printf("Insufficient space");
}
printf("Enter data of first node: ");
scanf("%d",&data);
head2->data=data;
head2->link=NULL;
temp=head2;
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

void printall(struct node* head)
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
}
void common(struct node *head1,struct node *head2)
{
	for(;head1!=NULL;head1=head1->link)
	{
		for(struct node *ptr=head2;ptr!=NULL;ptr=ptr->link)
		{
			if(ptr->data==head1->data)
				{
					printf("%d ",ptr->data);
				}
		}
	}
}
int main()
{
	int n1,n2;
	printf("Enter the value of n1: ");
	scanf("%d",&n1);
	list1(n1);
	printf("Enter the value of n2: ");
	scanf("%d",&n2);
	list2(n2);
	printall(head1);
	printf("\n");
	printall(head2);
	printf("\n");
	common(head1,head2);
}
