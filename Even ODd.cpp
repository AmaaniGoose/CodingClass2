#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head;
int res[100];

struct node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 


void list(int n)
{
struct node *temp,*newnode;
int i,data,count=0;
head=(struct node*)malloc(sizeof(node));

if(head==NULL)
{
	printf("Insufficient space");
}
printf("Enter data of first node: ");
scanf("%d",&data);
head->data=data;
head->link=NULL;
temp=head;
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

void printall(struct node *head)
{
	struct node *temp,*temp2;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
}

void rearrangedata()
{
	
int i;
struct node *temp;
temp=head;
while(temp->link!=NULL)
	{
		if((temp->data)%2==0)
		{	
			res[i]=temp->data;
			i++;
		}
		temp=temp->link;
	}
if((temp->data)%2==0)
	{
		res[i]=temp->data;
		i++;
	}

temp=head;

while(temp->link!=NULL)
	{
		if((temp->data)%2!=0)
		{	
			res[i]=temp->data;
			i++;
		}
		temp=temp->link;
	}
if((temp->data%2)!=0)
	{
		res[i]=temp->data;
		i++;
	}
	/*for(int j=0;j<i;j++)
	{
		printf("%d-> ",res[j]);
	}*/
}

void rearrange(int n)
{	
	int i;
	struct node *temp,*newnode;
	free(head);
	head->data=res[0];
	head->link=NULL;
	temp=head;
	for(i=1;i<n;i++)
	{
		newnode=getnode(res[i]);
		temp->link=newnode;
		temp=temp->link;
	}
}

int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	list(n);
	printall(head);
	printf("\n");
	rearrangedata();
	rearrange(n);
	printall(head);
	return 0;
}
