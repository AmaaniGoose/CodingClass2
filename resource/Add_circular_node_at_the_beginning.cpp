#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *temp1=NULL;
void create(struct node *temp,int n,struct node *temp1);
void print(struct node *temp,struct node *temp1);
void add(struct node *temp);
void add(struct node *temp)
{
	struct node *temp2,*temp1;
	temp1=temp;
	temp2=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data :  ");
	scanf("%d",&temp2->data);
	temp2->link=temp;
	while(temp1->link!=temp)
	{
		temp1=temp1->link;
	}
	temp1->link=temp2;
	temp=temp2->link;
	printf("Data after Adding node :  \n");
	print(temp2,temp2);
}
void print(struct node *temp,struct node *temp1)
{
	if(temp->link!=temp1)
	{
		printf("Data : %d\n",temp->data);
		print(temp->link,temp1);
	}
	else if(temp->link==temp1)
	{
		printf("Data : %d\n",temp->data);
	}
}
void create(struct node *temp,int n,struct node *temp1)
{
	if(n>0)
	{
		temp->link=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data :  ");
		scanf("%d",&temp->link->data);
		if(n==1)
		{
			temp->link->link=temp1;
		}
		else
		{
			temp->link->link=NULL;
		}
		temp=temp->link;
		create(temp,n-1,temp1);
	}
}
int main()
{
	int n;
	printf("Enter no of nodes :  ");
	scanf("%d",&n);
	struct node *head,*temp;
	head=(struct node*)malloc(sizeof(struct node));
	temp=head;
	temp1=head;
	printf("Enter Data :  ");
	scanf("%d",&head->data);
	head->link=NULL;
	create(temp,n-1,temp1);
	printf("Data as entered :  \n");
	print(temp1,temp1);
	temp1=head;
	add(temp1);
}
