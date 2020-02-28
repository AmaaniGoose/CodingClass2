#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *temp1=NULL;
void create(struct node *temp,int n);
void print(struct node *temp);
void add(struct node *temp);
void add(struct node *temp)
{
	if(temp->link!=NULL)
	{
		add(temp->link);
	}
	else if(temp->link==NULL)
	{
		struct node *temp2;
		temp2=(struct node *)malloc(sizeof(struct node));
		printf("Enter Data :  ");
		scanf("%d",&temp2->data);
		temp->link=temp2;
		temp2->link=NULL;
		temp2=NULL;
		free(temp2);
	}
	
}
void print(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("Data : %d\n",temp->data);
		print(temp->link);
	}
}
void create(struct node *temp,int n)
{
	if(n>0)
	{
		temp->link=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data :  ");
		scanf("%d",&temp->link->data);
		temp->link->link=NULL;
		temp=temp->link;
		create(temp,n-1);
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
	create(temp,n-1);
	printf("Data as entered :  \n");
	print(temp1);
	add(temp1);
	head=temp1;
	printf("Data as entered :  \n");
	print(temp1);
}
