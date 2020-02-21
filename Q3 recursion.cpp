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
struct node* traverse(int loc)
{
	struct node* temp=head;
	int count=1;
	while(count!=loc)
	{
		count++;
		temp=temp->link;
	}
	return temp;
	
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

void printallspecial()
{
	struct node* temp;
	temp=head;
	int count=1;
	while(temp!=NULL)
	{
		printf("%d{%d}->",temp->data,count);
		temp=temp->link;
		count++;
	}
}

void deletebeg()
{
	struct node* temp;
	temp=head;
	temp=temp->link;
	free(head);
	head=temp;
	
}

struct node* deleteend(struct node* head,int n)
{
	struct node* temp;
	temp=traverse(n-1);
	if(head==temp)
	{
		free(temp->link);
		temp->link=NULL;
	}
else
	{	

	head->link=deleteend(head->link,n);
	
	}
return head;
}

struct node* deletemid(struct node *head,int loc)
{	
struct node* temp=traverse(loc);
if(head==temp)
	{
		struct node* temp2=temp->link->link;
		free(temp->link);
		temp->link=temp2;
	}
else
	{	
	
	head->link=deletemid(head->link,loc);
	
	}
return head;

}
int main()
{
	int n,i,loc;
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
	int ch;
	int ch1=1;
	while(ch1==1)
	{
	printf(" \nMenu for operations: Enter 1 for deletion at beginning and 2 for deletion at end and 3 for deletion at desired spot: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: deletebeg();
				printall(head);
		
		break;
		
		case 2: head=deleteend(head,n--);
				printall(head);
		
		break;
		
		case 3: printf("Enter location: ");
				scanf("%d",&loc);
				deletemid(head,loc);
				printall(head);
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	
	return 0;
}
