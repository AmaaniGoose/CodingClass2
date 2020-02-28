#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *fwd;
	struct node *bkd;
};
void reverse(struct node *temp);
void create(struct node *temp,int n);
void print(struct node *temp);
void printrev(struct node *temp);
void add(struct node *temp,struct node *temp3,int m);
void add(struct node *temp,struct node *temp3,int m)
{
	if(temp->data!=m)
	{
		add(temp->fwd,temp3,m);
	}
	else if (temp->data==m)
	{
		struct node *temp2,*temp1;
		temp1=temp->fwd;
		temp2=(struct node *)malloc(sizeof(struct node));
		printf("Enter Data :  ");
		scanf("%d",&temp2->data);
		temp2->fwd=temp1;
		temp2->bkd=temp;
		temp->fwd=temp2;
		temp1->bkd=temp2;
		printf("Data as entered :  \n");
		print(temp3);
		temp1=temp;
		printf("Reversed order :  \n");
		reverse(temp1);
		temp2=NULL;
		temp1=NULL;
		temp=NULL;
		free(temp);
		free(temp1);
		free(temp2);
	}
}
void reverse(struct node *temp)
{
	struct node *temp1;
	temp1=temp;
	while(temp1->fwd!=NULL)
	{
		temp1=temp1->fwd;
	}
	printrev(temp1);
	temp=NULL;
	free(temp);
}
void print(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("Data : %d\n",temp->data);
		print(temp->fwd);
	}
	temp=NULL;
	free(temp);
}
void printrev(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("Data : %d\n",temp->data);
		printrev(temp->bkd);
	}
	temp=NULL;
	free(temp);
}
void create(struct node *temp,int n,struct node *temp1)
{
	if(n>0)
	{
		temp->fwd=(struct node*)malloc(sizeof(struct node));
		temp=temp->fwd;
		printf("Enter Data :  ");
		scanf("%d",&temp->data);
		temp->fwd=NULL;
		temp->bkd=temp1;
		create(temp,n-1,temp1->fwd);
	}
	temp=NULL;
	free(temp);
	temp1=NULL;
	free(temp1);
}
int main()
{
	int n;
	printf("Enter no of nodes :  ");
	scanf("%d",&n);
	struct node *head;
	struct node *temp;
	struct node *temp1;
	head=(struct node * )malloc(sizeof(struct node));
	temp=head;
	temp1=head;
	printf("Enter Data :  ");
	scanf("%d",&head->data);
	head->fwd=NULL;
	head->bkd=NULL;
	create(temp,n-1,temp1);
	printf("Data as entered :  \n");
	print(temp1);
	temp=head;
	printf("Reversed order :  \n");
	temp=head;
	reverse(temp);
	int m;
	printf("\nEnter the data of the node after which you want to add the node :  ");
	scanf("%d",&m);
	temp=head;
	add(temp,temp,m);
	temp1=NULL;
	temp=NULL;
	free(temp);
	free(temp1);
}
