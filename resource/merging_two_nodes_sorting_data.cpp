#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *temp1=NULL;
struct node *temp2=NULL;
node* sort(node* head, node* head1);
void create(struct node *temp,int n);
void print(struct node *temp);
struct node* sort(struct node* temp,struct node* temp1) 
{ 
	struct node *p = NULL;
	if (temp == NULL) 
	{
		return (temp1); 
	}
	else if (temp1 == NULL) 
	{
		return (temp); 
	}
	if (temp->data < temp1->data)
	{ 
		p = temp; 
		p->link = sort(temp->link, temp1); 
	} 
	else if(temp->data > temp1->data)
	{ 
		p = temp1; 
		p->link = sort(temp,temp1->link); 
	}
	else if(temp->data == temp1->data) 
	{
		p=temp;
		p->link=sort(temp->link,temp1->link);
	} 
	return p; 
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
	printf("Enter Data of the 1st node :  \n");
	printf("Enter Data :  ");
	scanf("%d",&head->data);
	head->link=NULL;
	create(temp,n-1);
	printf("Data as entered :  \n");
	print(temp1);
	struct node *head1,*temp3;
	head1=(struct node *)malloc(sizeof(struct node ));
	temp2=head1;
	temp3=head1;
	printf("Enter Data of the 2nd node :  \n");
	printf("Enter Data :  ");
	scanf("%d",&head1->data);
	head1->link=NULL;
	create(temp3,n-1);
	print(temp2);
	temp1=head1;
	temp=head;
	temp1=sort(temp,temp1);
	printf("After sorting the data in th lists :  \n");
	print(temp1);
}
