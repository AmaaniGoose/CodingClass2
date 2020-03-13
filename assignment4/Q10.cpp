#include<stdio.h>
#include<limits.h>
#define max 100
int stack[max];
int top=-1;
int size=0;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
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
void getarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void printarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
int *swapper(int a[],int k)
{int i;
	int res[100];
	for(i=0;i<k;i++)
	{
		push(a[i]);
	}
	for(i=0;i<k;i++)
	{
		int temp=pop();
		swap(a[i],temp);
	}
}

int main()
{
int a[100],n,k;
scanf("%d",&n);
scanf("%d",&k);
getarray(a,n);
printarray(a,n);
swapper(a,k);
printarray(a,n);

}
