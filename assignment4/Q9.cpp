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
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void swaparr(int * a, int * b, int size)
{
	for(int i=0;i<size;i++)
	{
		swap(a[i],b[i]);
	}
/*
    int * sourceArrEnd = (sourceArr + (size - 1));
    int * destArrEnd   = (destArr + (size - 1));
    while(sourceArr <= sourceArrEnd && destArr <= destArrEnd)
    {
        *sourceArr ^= *destArr;
        *destArr   ^= *sourceArr;
        *sourceArr ^= *destArr;
        sourceArr++;
        destArr++;
    }
*/
}
int IsEmptyqueue(int size)
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

int IsFullqueue(int size)
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
void enqueue(int data,int &size,int *rear,int queue[])
{
	if(IsFullqueue(size))
	{
		printf("Queue OVERFLOW");
		return;
	}
	*rear=(*rear+1)%max;
	queue[*rear]=data;
	size++;
}
int dequeue(int &size,int *front,int queue[])
{
	if(IsEmptyqueue(size))
	{
		return INT_MIN;
	}
	int data=queue[*front];
	*front=(*front+1)%max;
	size--;
	return data;
}

void push(int data)
{
	enqueue(data,size2,&rear2,queue2);
	while(!(IsEmptyqueue(size1)))
	{
		int temp=dequeue(size1,&front1,queue1);
		enqueue(temp,size2,&rear2,queue2);
	}
	swaparr(queue1,queue2,100);
	swap(rear1,rear2);
	swap(front1,front2);
	swap(size1,size2);
	stacksize++;
}
int pop()
{
	if(stacksize==0)
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	int data=dequeue(size1,&front1,queue1);
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
				for(int i=0;i<100;i++)
				{
					printf("%d ",queue1[i]);
				}
				printf("size 1 is %d and size 2 is %d stacksize is %d: ",size1,size2,stacksize);
				
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
