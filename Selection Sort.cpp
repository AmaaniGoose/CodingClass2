#include<stdio.h>
#include <sys/time.h>
#include<stdlib.h>
//#include <chrono> 
//#include <iostream>
//using namespace std;
//using namespace std::chrono;
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
void selectionsort(int A[],int n)
{
	int swaps=0,comp=0;
	int i,j,min;
  	for(i=0;i<n-1;i++)
  	{	
  		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
				min=j;
				comp++;
		}
		swap(&A[i],&A[min]);	
		swaps++;
	}
	printf("for n= %d %d %d \n",n,swaps,comp);
}

int main()
{int j=0;
int n=30;
//while(j<4)
{

	struct timeval  tv1, tv2;
	int A[n],i;
	printf("\n");
	int k=0;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		A[i]=rand();
	}
	print(A,n);
	printf("\n");
	//auto start = high_resolution_clock::now();
	selectionsort(A,n);
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cout <<duration.count()<< endl;
	print(A,n);
	printf("\n");
	n+=3000;	
	j++;

}
	return 0;
	
}
