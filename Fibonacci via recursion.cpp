#include<stdio.h>
int fib(int n)
{if(n<=1)
	return n;
return fib(n-1)+fib(n-2);
}
int main()
{int n;
scanf("%d",&n);
printf("The value of nth element of fibonacci sequence is %d ",fib(n));
return 0;
}
