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
void eval(char *s)
{
	char rev[100];
	for(int i=0;i<strlen(s);i++)	
	{
		push(s[i]);
	}
	for(int i=0;i<strlen(s);i++)	
	{
		rev[i]=pop();
	}
	if(strcmp(rev,s)==0)
	{
		printf("Its a palindrome");
	}
	else
	{
		printf("Not a palindrome");
	}
}
int main()
{
	int res;
	char exp[100];
	printf("Enter experssion: ");
	scanf("%s",&exp);
	eval(exp);
	return 0;
}
