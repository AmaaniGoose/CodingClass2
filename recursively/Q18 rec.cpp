#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 
void printall(node* temp)
{
	if(temp->link!=head)
	{
		printf("%d->",temp->data);
		printall(temp->link);
	}
	if(temp->link==head)
		printf("%d->",temp->data);

}

void list(node* temp,int n)
{
	if(n>0)
	{
		temp->link=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->link->data);
		temp->link->link=head;
		list(temp->link,n-1);
	}

}

void deletebeg(struct node* temp)
{static struct node* temp2=head;
	if(temp->link==head)
	{
	temp->link=head->link;
	free(temp2);
	head=temp->link;
	return;
	}
	deletebeg(temp->link);
}

void deleteend(struct node* temp)
{static struct node* temp2;
	if(temp->link->link==head)
	{
		temp2=temp->link;
		temp->link=head;
		free(temp2);
		return;
	}
	deleteend(temp->link);
}

int main()
{
	int n,data;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	if(head==NULL)
	{
		printf("Insufficient space");
	}
	printf("Enter data of first node: ");
	scanf("%d",&data);
	head->data=data;
	head->link=NULL;
	list(head,n-1);
	printall(head);
	int ch;
	int ch1=1;
	while(ch1==1)
	{
	
	printf(" \nMenu for operations: Enter 1 for deletion at beginning and 2 for deletion at end and 3 for deleteion at desired spot: ");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: deletebeg(head);
				printall(head);
				n++;
		
		break;
		
		case 2:	deleteend(head);
				printall(head);
				n++;
		
		break;
		
	}
	printf("Enter more? 1 for yes and 0 for no ");
	scanf("%d",&ch1);
	}
	return 0;	
}
