#include<stdio.h>
#include <sys/time.h>
#include<stdlib.h>
//#include <chrono> 
//#include <iostream>
//using namespace std;
//using namespace std::chrono;		//Library to calulcate time to the highest precision
void swap(int *a,int *b)
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
void insertionsort(int A[],int n)
{
	int swaps=0,comp=0;
	int i,j,k;
  	for(i=1;i<=n-1;i++)
  	{
  		k=A[i];
  		j=i;
  		while(A[j-1]>k && j>=1)
  		{
  			A[j]=A[j-1];
  			j--;
  			comp++;
  			swaps++;
		  }
		  A[j]=k;	//Insertion sort code
		  swaps++;
		  comp++;
	}
	printf("Swaps = %d and comparisons = %d for n= %d ",swaps,comp,n);
}

int main()
{int j=0;
int n=30;	//Input size
//while(j<4)
{

	struct timeval  tv1, tv2;
	int A[n],i;
	printf("\n");
	int k=0;
	srand(time(0));		//Random number generator
	for(i=0;i<n;i++)
	{
		A[i]=rand();
	}
	print(A,n);
	printf("\n");
	//auto start = high_resolution_clock::now();
	insertionsort(A,n);
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	print(A,n);
	printf("\n");
	n+=3000;	
	j++;

}
	return 0;
}
