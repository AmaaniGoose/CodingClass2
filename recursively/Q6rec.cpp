#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };

struct node *head=(struct node*)malloc(sizeof(node));
struct node *head1=(struct node*)malloc(sizeof(node));
node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 

struct node* list(struct node* head,int data)
{
if(head==NULL)
	{
		return getnode(data);
	}
else
	{	

	head->link=list(head->link,data);
	
	}
return head;
}
void printall(struct node* head) 
{ 
    if (head == NULL) 
       return; 
	    
    printf("%d->",head->data);
  
 	printall(head->link); 
} 
void common(struct node *head1,struct node *head2,int n)
{
	if(n>0)
	{	struct node* ptr=head2;
		while(ptr->link!=NULL)
		{
		
		if(ptr->data==head1->data)
		{
			printf("%d ",ptr->data);
		}
		ptr=ptr->link;
		}
	common(head1->link,head2,n-1);
	}
	
}
int main()
{
	int n,n1,i;
	head=NULL;
	head1=NULL;
	printf("Enter the value of n1: ");
	scanf("%d",&n);
	printf("Enter the value of n2: ");
	scanf("%d",&n1);
	for(i=0;i<n;i++)
	{
		int data;
		printf("Enter data for node %d : ",i+1);
		scanf("%d",&data);
		head=list(head,data);
	}
	for(i=0;i<n1;i++)
	{
		int data;
		printf("Enter data for node %d : ",i+1);
		scanf("%d",&data);
		head1=list(head1,data);
	}
	printall(head);
	printf("\n");
	printall(head1);
	printf("\n");
	common(head,head1,n);
}
