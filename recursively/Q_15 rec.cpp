#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head,*temp1;
void print(struct node *temp);
void print(struct node *temp)
{
	if(temp!=head)
	{
		printf("%d ",temp->data);
		print(temp->link);
	}
}
void create(struct node* temp,int n);
void create(struct node* temp,int n)
{
	if(n>0)
	{
		temp->link=(struct node*)malloc(sizeof(struct node));
		printf("enter data : ");
		scanf("%d",&temp->link->data);
		temp->link->link=temp1;
		create(temp->link,n-1);
	}
}
main()
{
	int i,j,n;
	printf("enter no. of circular nodes u want : ");
	scanf("%d",&n);
	struct node *head,*temp;
	head=(struct node*)malloc(sizeof(struct node));
	temp=head;
	printf("enter data : ");
	scanf("%d",&head->data);
	head->link=temp;
	temp=head;
	create(temp,n-1);
	printf("printing the data :");
	temp=head;
	print(temp);	
}
