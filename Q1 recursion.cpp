#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };

struct node *head=(struct node*)malloc(sizeof(node));

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
int main()
{
	int n,i;
	head=NULL;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int data;
		printf("Enter data for node %d : ",i+1);
		scanf("%d",&data);
		head=list(head,data);
	}
	printall(head);
}
