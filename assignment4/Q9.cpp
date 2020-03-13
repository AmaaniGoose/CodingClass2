#include<stdio.h>
#include<limits.h>
#define max 100
int queue1[max];
int queue2[max];
int stacksize=0;
int front1=0;
int rear1=max-1;
int front2=0;
int rear2=max-1;
int size1=0;
int size2=0;
void swap(int* a,int *b)
{
	int *temp=a;
	a=b;
	b=temp;
}
int IsEmptyqueue1()
{
	if(size1==0)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int IsFullqueue1()
{
	if(size1==max)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}
int IsEmptyqueue2()
{
	if(size2==0)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int IsFullqueue2()
{
	if(size2==max)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}
void enqueue1(int data)
{
	if(IsFullqueue1())
	{
		printf("Queue OVERFLOW");
		return;
	}
	rear1=(rear1+1)%max;
	queue1[rear1]=data;
	size1++;
}
int dequeue1()
{
	if(IsEmptyqueue1())
	{
		return INT_MIN;
	}
	int data=queue1[front1];
	front1=(front1+1)%max;
	size1--;
	return data;
}
void enqueue2(int data)
{
	if(IsFullqueue2())
	{	
		return;
	}
	rear2=(rear2+1)%max;
	queue2[rear2]=data;
	size2++;
}
int dequeue2()
{
	if(IsEmptyqueue2())
	{

		return INT_MIN;
	}
	int data=queue2[front2];
	front2=(front2+1)%max;
	size2--;
	return data;
}

void push(int data)
{
	enqueue2(data);
	while(!(IsEmptyqueue1()))
	{
		int temp=dequeue1();
		enqueue2(temp);
	}
	swap(&queue2,&queue1);
	stacksize++;
}
int pop()
{
	if(stacksize==0)
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	int data=dequeue1();
	stacksize--;
	return data;
}
/*
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
}*/
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
				
		/*case 3: printf("The top element is %d\n",topele());
		
		break;
		
		case 4: printf("The size is %d\n",stacksize());
		
		break;
		
		case 5: (IsEmptyStack())?printf("Its empty\n"):printf("Not empty\n");
		
		break;
		
		case 6: (IsFullStack())?printf("Its full\n"):printf("Not full\n");*/
	
	}
	printf("Enter more? ");
	scanf("%d",&ch1);
	}
}
