#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head;

node* getnode(int data) 
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
	newnode->link=head;
	temp=newnode;
	count++;
}
}
void printall()
{
	struct node* temp;
	temp=head;
	while(temp->link!=head)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d->",temp->data);
}
void reverse(struct node **head) 
{

    struct node *prev, *cur, *link, *last;


    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }



    last = *head;

    prev  = *head;
    cur   = (*head)->link;
    *head = (*head)->link;

  
    while (*head != last)
    {
        *head = (*head)->link;
        cur->link = prev;

        prev = cur;
        cur  = *head;
    }

    cur->link = prev;
    *head = prev;       
}

int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	list(n);
	printall();
	reverse(&head);
	printf("\n");
	printall();
}
