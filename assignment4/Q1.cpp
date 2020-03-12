#include<stdio.h>
#include<limits.h>
#define max 100
int stack[max];
int top=-1;
int size=0;
void push(int data)
{
	if(top==max-1)
	{
		printf("STACK OVERFLOW");
		return;
	}
	
	stack[++top]=data;
	size++;
}
int pop()
{
	if(top==-1)
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	
	int data=stack[top--];
	size--;
	return data;
}

int topele()
{
	if(top==-1)
	{
		printf("No elements in stack");
		return INT_MIN; 
	}
	
	return stack[top];
}

int stacksize()
{
	return size;
}

int IsEmptyStack()
{
	if(top==-1)
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
	if(top==max-1)
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
