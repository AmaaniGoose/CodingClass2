#include<stdio.h>
#include<string.h>
struct cust{
	char sname[100];
	char fname[100];
	char mname[100];
	char phone[100];		
};


void read(struct cust A[],int n)
{int i;
for(i=0;i<n;i++)
	{	
		scanf("%s",A[i].sname);
		scanf("%s",A[i].fname);
		scanf("%s",A[i].mname);
		scanf("%s",A[i].phone);

	}
}
void write(struct cust A[],int n)
{
int i,j=0;
for(i=0;i<n;i++)
	{	
	printf("%s,%c.%c %s\n",A[i].sname,A[i].fname[0],A[i].mname[0],A[i].phone);

	}

}
int main()
{int n;
printf("Enter the number of entries: ");
scanf("%d",&n);
struct cust A[n];
printf("Enter name and telephone numbers: \n");
read(A,n);
printf("Customer List: \n");
write(A,n);
}

