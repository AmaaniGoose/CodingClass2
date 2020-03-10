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

void swapper(struct node* head) 
{ 
 
  if ((!head) || !head->link) 
      return;
  int temp;
  struct node* p = head;
  struct node* q = head->link;
  if(q) 
  {
     temp = p->data;
     p->data = q->data;
     q->data = temp;
     /*/p = q->link;
     q = p?p->link:0;*/

  } 
swapper(head->link->link);
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
	swapper(head);
	printf("\n");
	printall(head);
	return 0;
}
