#include<stdio.h>
#include<limits.h>
#define max 100
int stack1[max];
int stack2[max];
int top1=-1;
int top2=-1;
int size=0;
int size1=0;
int size2=0;
void push1(int data)
{
	if(top1==max-1)
	{
		printf("STACK OVERFLOW");
		return;
	}
	
	stack1[++top1]=data;
	size1++;
}
int pop1()
{
	if(top1==-1)
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	
	int data=stack1[top1--];
	size1--;
	return data;
}
void push2(int data)
{
	if(top2==max-1)
	{
		printf("STACK OVERFLOW");
		return;
	}
	
	stack2[++top2]=data;
	size2++;
}
int pop2()
{
	if(top2==-1)
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	
	int data=stack2[top2--];
	size2--;
	return data;
}

int IsEmptyqueue()
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

int IsFullqueue()
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
void enqueue(int data)
{
	if(IsFullqueue())
	{
		printf("Queue OVERFLOW");
		return;
	}
	while(size1!=0)
	{
		int temp=pop1();
		push2(temp);
	}
	push1(data);
	while(size2!=0)
	{
		int temp=pop2();
		push1(temp);
	}
	size++;
}
int dequeue()
{
	if(IsEmptyqueue())
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	int data=pop1();
	size--;
	return data;
}



int queuesize()
{
	return size;
}


int main()
{
	int ch,ch1=1,data,dequeueele;
	while(ch1==1)
	{
	printf("Press 1 for enqueue, 2 for dequeue 3 for top element(depricated) 4 for size 5 for checking empty 6 for checking full: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the element to be enqueueed: ");
				scanf("%d",&data);
				enqueue(data);
				
		break;
		
		case 2: dequeueele=dequeue();
				printf("dequeueped element is: %d \n",dequeueele);
		
		break;
				
		case 3: //printf("The top element is %d\n",topele());
		
		break;
		
		case 4: printf("The size is %d\n",queuesize());
		
		break;
		
		case 5: (IsEmptyqueue())?printf("Its empty\n"):printf("Not empty\n");
		
		break;
		
		case 6: (IsFullqueue())?printf("Its full\n"):printf("Not full\n");
	
	}
	printf("Enter more? ");
	scanf("%d",&ch1);
	}
}
