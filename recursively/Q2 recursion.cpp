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

void printallspecial(struct node* head) 
{ 
	int count=1;
    if (head == NULL) 
       return; 
	    
    printf("%d{%d}->",head->data,count);
    count++;
  	
 	printall(head->link); 
} 

void insertbeg()
{
	struct node *newnode;
	int data;
	printf("Enter data for new node : ");
	scanf("%d",&data);
	newnode=getnode(data);
	newnode->link=head;
	head=newnode;
	
}

struct node* insertend(struct node* head,int data)
{
	if(head==NULL)
	{
		return getnode(data);
	}
else
	{	

	head->link=insertend(head->link,data);
	
	}
return head;
}

struct node* insertmid(struct node* head,int data,int loc)
{
struct node* temp=traverse(loc);
if(head==temp)
	{
		struct node* temp2=temp->link;
		struct node* newnode=getnode(data);
		temp->link=newnode;
		newnode->link=temp2;
		
	}
else
	{	
	
	head->link=insertmid(head->link,data,loc);
	
	}
return head;
}
int main()
{
	int n,i,data,loc;
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
	
	printf(" \nMenu for operations: Enter 1 for insertion at beginning and 2 for insertion at end and 3 for insertion at desired spot: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: insertbeg();
				printall(head);
		
		break;
		
		case 2:
				printf("Enter data for node %d : ",i+1);
				scanf("%d",&data);
				head=list(head,data);
				printall(head);
		
		break;
		
		case 3: 
				printf("Enter data for node : ");
				scanf("%d",&data);
				printf("Enter location: ");
				scanf("%d",&loc);
				head=insertmid(head,data,loc);
				printall(head);
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	return 0;
}
