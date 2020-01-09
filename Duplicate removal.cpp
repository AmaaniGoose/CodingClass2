  #include<stdio.h>
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

void bsort(int A[],int N)
{int i,j;

for(i=0;i<N-1;i++)
{
for(j=0;j<N-i-1;j++)
{	if(A[j]>A[j+1])
	{	swap(&A[j],&A[j+1]);
	}
}

}
}

int dupes(int A[], int N)
{
	if(N==0||N==1)
	return N;
	int temp[N],i,j=0;
	for(i=0;i<N-1;i++)
	{if(A[i]!=A[i+1])
		{
		temp[j++]=A[i];
		}
	}
temp[j++]=A[N-1];
for(i=0;i<j;i++)
{A[i]=temp[i];
}
return j;
}

void inputarray(int A[],int N)
{int i;
for(i=0;i<N;i++)
{scanf("%d",&A[i]);
}
}
void printarray(int A[],int N)
{int i;
for(i=0;i<N;i++)
{printf("%d ",A[i]);
}
}
int main()
{
int N,i,j,count=0;
scanf("%d",&N);
int A[N];
inputarray(A,N);
printf("\n");
printf("Now Sorting \n");
bsort(A,N);
printarray(A,N);
printf("\n");
printf("\nNOW DUPLICATES SHALL BE REMOVED \n");
N=dupes(A,N);
printarray(A,N);
return 0;
}
