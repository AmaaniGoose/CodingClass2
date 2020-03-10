#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head1,*head2,*head3,*head4;

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

struct node* merge(struct node* head1, struct node* head2)  
{ 
  struct node* head3 = NULL; 
  
 
  if (head1 == NULL)  
     return(head2); 
  else if (head2==NULL)  
     return(head1); 
  

  if (head1->data < head2->data)  
  { 
     head3 = head1; 
     head3->link = merge(head1->link, head2); 
  } 
  else 
  { 
     head3 = head2; 
     head3->link = merge(head1, head2->link); 
  } 
  return(head3); 
}

struct node* removedupes(struct node *head3) 
{	
	
	struct node *temp=head3;
	struct node *temp2;
	while(temp->link!=NULL)
		{
			if(temp->data==temp->link->data)
			{
				temp2=temp->link->link;
				free(temp->link);
				temp->link=temp2;
			}
			temp=temp->link;
		}
	return head3;
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
	head3=merge(head1,head2);
	head4=removedupes(head3);
	printall(head4);
}
