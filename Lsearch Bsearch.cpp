#include<stdio.h>
#include<conio.h>
int Lsearch(int A[],int n,int ele)
{int i;
for(i=0;i<n;i++)
{if(A[i]==ele)
	{
		return i;
	
	}
}
return -2;
}

void swap(int *a,int *b)
{int temp=*a;
*a=*b;
*b=temp;
}


void Bsort(int A[],int n)
{int i,j;
for(i=0;i<n;i++)
	{for(j=0;j<n-i-1;j++)
		{if(A[j]>A[j+1])
			{swap(&A[j],&A[j+1]);
			}
		}
	}
}
int Bsearch(int A[],int n,int ele)
{Bsort(A,n);
int i,mid;
int first=0;
int last=n-1;
mid=(first+last)/2;
while(first<=last)
{mid=(first+last)/2;
if(A[mid]==ele)
	{return mid;
	}
if(A[mid]>ele)
	{last=mid-1;
	}

else
first=mid+1;
}
return -2;
}




int main()
{int n,ele,index;
scanf("%d\n",&n);
int A[n];
for(int i=0;i<n;i++)
{A[i]=0;
}
for(int i=0;i<n;i++)
{scanf("%d",&A[i]);
}
printf("Enter ele: ");
scanf("%d",&ele);
int ch;
printf("Enter choice(1 for Linear and 2 for Binary): ");
scanf("%d",&ch);
switch(ch)
{case 1: 

index=Lsearch(A,n,ele)+1;
printf("Element found at index: %d", Lsearch(A,n,ele)+1);

break;
case 2: index=Bsearch(A,n,ele)+1;
printf("Element found at index: %d", Bsearch(A,n,ele)+1);
}

return 0;
}
