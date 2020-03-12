#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> 
#define max 100
char stack[max];
int top=-1;
int size=0;

void push(char data)
{
	if(top==max-1)
	{
		printf("STACK OVERFLOW");
		return;
	}
	
	stack[++top]=data;
	size++;
}
char pop()
{
	if(top==-1)
	{
		printf("UNDERFLOW");
	}
	
	int data=stack[top--];
	size--;
	return data;
}

char topele()
{
	if(top==-1)
	{
		printf("No elements in stack"); 
	}
	else
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

int eval(char *s)
{
	int res,op1,op2;
	for(int i=0;i<strlen(s);i++)
	{
		if(isdigit(s[i]))
		{
			push(s[i]-'0');
		}
		else
		{
			op1=pop();
			op2=pop();
			switch(s[i])
			{
				case '+': push(op1+op2);
				break;
				case  '*': push(op1*op2);
				break;
				case '-': push(op2-op1);
				break;
				case '/': push(op2/op1);
				break;
			}
		}
	}
	res=pop();
	return res;
	
}//231*+9-
int main()
{
	int res;
	char exp[100];
	printf("Enter experssion: ");
	scanf("%s",&exp);
	res=eval(exp);
	printf("result= %d",res);
	return 0;
}
