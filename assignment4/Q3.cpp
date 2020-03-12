#include<stdio.h>
#include<limits.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
int size=0;
int precedence(char c) 
{ 
    if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
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

void infixtopostfix(char *s)
{
	int l=strlen(s);
	char postfix[100];
	int j=0;
	int i;
	for(i=0;i<l;i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
		{
			postfix[j++]=s[i];
		}
		else if(s[i]=='(')
		{
			push(s[i]);
		}
		else if(s[i]==')')
		{
			while(!(IsEmptyStack()) && topele()!='(')
			{
				postfix[j++]=pop();
			}
			if(topele()=='(')
			{
				char ch=pop();
			}
		}
		else
		{
			while(!(IsEmptyStack) && precedence(s[i])<=precedence(topele()))
			{
				postfix[j++]=pop();
			}
			push(s[i]);
		}
		
	}
	while(!(IsEmptyStack()))
	{
		postfix[j++]=pop();
	}
	printf("The converted postfix expression is: %s",postfix);
}
int main()
{
	int i=1;
	char infix[100];
	printf("Enter infix: ");
	scanf("%s",&infix);
	printf(" The given infix is: %s \n",infix);
	printf("%d",strlen(infix));
	infixtopostfix(infix);
	return 0;
}
