#include<stdio.h>
#include<string.h>
struct cust{
	char name[100];
};


void read(struct cust A[],int n)
{int i;
for(i=0;i<=n;i++)
	{	
		gets(A[i].name);

	}
}
void write(struct cust A[],int n)
{
int i,j=0;
for(i=0;i<=n;i++)
	{	
	printf("%s \n",A[i].name);
	}
}
int main()
{int n;
scanf("%d",&n);
struct cust A[n];
printf("Enter name and telephone numbers: \n");
read(A,n);
printf("Customer List: \n");
write(A,n);
}

