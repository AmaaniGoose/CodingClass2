#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *fwd;
	struct node *back;
};

void print(struct node*temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		print(temp->fwd);
	}
}

void create(struct node*temp,int n)
{
	if(n>0)
	{
		temp->fwd=(struct node*)malloc(sizeof(struct node));
		printf("enter data : ");
		scanf("%d",&temp->fwd->data);
		temp->fwd->back=temp;
		temp->fwd->fwd=NULL;
		create(temp->fwd,n-1);
	}
}

int main()
{
	int i,j,n;
	printf("enter no. of nodes you want: ");
	scanf("%d",&n);
	struct node *head,*temp;
	head=(struct node*)malloc(sizeof(struct node));
	temp=head;
	printf("enter data : ");
	scanf("%d",&head->data);
	head->back=NULL;
	head->fwd=NULL;
	create(temp,n-1);
	printf("printing the data :");
	temp=head;
	print(temp);
	return 0;	
}
