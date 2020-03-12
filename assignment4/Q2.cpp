#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define max 100
struct node
{
	int data;
	struct node* link;
};
struct node* top=(struct node*)malloc(sizeof(struct node));
int size=0;
struct node* getnode(int data)
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	return newnode;
}
void push(int data)
{
	if(size==max)
	{
		printf("STACK OVERFLOW");
		return;
	}
	else if(size==0)
	{
		top->data=data;
		top->link=NULL;
		size++;
		return;
	}
	struct node* newnode=getnode(data);
	newnode->link=top;
	top=newnode;
	size++;
}
int pop()
{
	if(size==0)
	{
		printf("UNDERFLOW \n");
		return INT_MIN;
	}

	int data=top->data;
	top=top->link;
	size--;
	return data;
}

int topele()
{
	if(size==0)
	{
		printf("No elements in stack");
		return INT_MIN; 
	}
	
	return top->data;
}

int stacksize()
{
	return size;
}

int IsEmptyStack()
{
	if(size==0)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int IsFullStack()
{
	if(size==max)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}
int main()
{
	int ch,ch1=1,data,popele;
	while(ch1==1)
	{
	printf("Press 1 for push, 2 for pop 3 for top element 4 for size 5 for checking empty 6 for checking full: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the element to be pushed: ");
				scanf("%d",&data);
				push(data);
				
		break;
		
		case 2: popele=pop();
				printf("Popped element is: %d \n",popele);
		
		break;
				
		case 3: printf("The top element is %d\n",topele());
		
		break;
		
		case 4: printf("The size is %d\n",stacksize());
		
		break;
		
		case 5: (IsEmptyStack())?printf("Its empty\n"):printf("Not empty\n");
		
		break;
		
		case 6: (IsFullStack())?printf("Its full\n"):printf("Not full\n");
	
	}
	printf("Enter more? ");
	scanf("%d",&ch1);
	}
}
