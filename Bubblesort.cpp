#include<stdio.h>
#include <sys/time.h>

#include<stdlib.h>
//#include <iostream>
//#include <iomanip>
//using namespace std;
//using namespace std::chrono;	//Library to calculate time with highest precision
void swap(int *a,int *b)		//Code to swap
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int A[],int n)		
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
void bubblesort(int A[],int n)
{
	int swaps=0,comp=0;
	int i,j;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
				//print(A,n);
				//printf("\n");
				comp++;
				swaps++;
				//printf("comp= %d swap=%d ",comp,swaps);
			}
			else
			{
				comp++;
				//print(A,n);
				//printf("\n");
				//printf("comp= %d swap= %d ", comp, swaps);
			}
		}
	}
	printf("Swaps = %d and comparisons = %d for n= %d ",swaps,comp,n);
}

int main()
{int j=0;
int n=30;		//Input size
//while(j<4)
{

	struct timeval start, end;
	int A[n],i;
	printf("\n");
	int k=n;			//can be used to fill array with best and worst case 
	srand(time(0));		//seeding the random
	for(i=0;i<n;i++)
	{
		A[i]=k;	
		k--;//random numbers
	}
	print(A,n);
	printf("\n");
	
	//Code to calculate time begins	
	gettimeofday(&start, NULL);
	bubblesort(A,n);
	gettimeofday(&end, NULL);
	double time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec -start.tv_usec)) * 1e-6; 
  
    //cout << "Time taken by program is : " << fixed << time_taken << setprecision(6); 
    //cout << " sec" << endl;
    printf("Time taken= %lf",time_taken);
	print(A,n);
	//Code to calculate time ends
	printf("\n");
	j++;
	n+=3000;
}
	return 0;
	
}
