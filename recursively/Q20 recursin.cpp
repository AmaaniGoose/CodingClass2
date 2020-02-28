#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* head2=(struct node*)malloc(sizeof(struct node));
struct node *temp1=head;
void print(struct node *temp)
{
	if(temp->link!=temp)
	{
		printf("%d ",temp->data);
		print(temp->link);
	}
	else
	{
		printf("%d ",temp->data);
		return;
	}
}

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
void split(int n)
{
	int i;
	struct node *temp,*temp3;
	temp=head;
	temp3=head;
	while(temp3->link!=head)
	{
		temp3=temp3->link;
	}
	head2=(struct node*)malloc(sizeof(struct node));
	if(n%2==0)
	{
		for(i=1;i<n/2;i++)
		{
			temp=temp->link;
		}
		head2=temp->link;
		temp->link=head;
		temp3->link=head2;
	}
	else
	{
		for(i=1;i<(n+1)/2;i++)
		{
			temp=temp->link;
		}
		head2=temp->link;
		temp->link=head;
		temp3->link=head2;
	}
}
int main()
{
	int i,j,n;
	printf("enter no. of circular nodes u want : ");
	scanf("%d",&n);
	struct node *temp;
	temp=head;
	printf("enter data : ");
	scanf("%d",&head->data);
	head->link=temp;
	create(temp,n-1);
	printf("printing the data :");
	print(head);
	/*split(n);
	print(head);
	printf("\n");
	print(head2);*/
	return 0;	
}
