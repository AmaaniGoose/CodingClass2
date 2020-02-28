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
void reverse_in_pairs(struct node *temp,struct node *temp1,int n);
void reverse_in_pairs(struct node *temp,struct node *temp1,int n)
{
	struct node *temp2;
	temp2=temp->link;
	if(temp->link!=NULL && temp2->link!=NULL)
	{
		int m;
		m=temp->data;
		temp->data=temp2->data;
		temp2->data=m;
		reverse_in_pairs(temp2->link,temp1,n);
	}
	else if(n%2==0 && temp2->link==NULL)
	{
		int m;
		m=temp->data;
		temp->data=temp2->data;
		temp2->data=m;
	}
	if(temp->link==NULL||temp2->link==NULL)
	{
		printf("\nData after reversing in pairs :  \n");
		print(temp1);
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
	temp=head;
	temp1=head;
	reverse_in_pairs(temp,temp1,n);
}
