#include<stdio.h>
#include <sys/time.h>
//#include<stdlib.h> 			//Uncomment to use for time analysis
//#include <chrono> 
//#include <iostream>
//using namespace std;
//using namespace std::chrono;
int swaps=0;
int comp=0;
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
int partition(int A[],int low,int high)
{
	int pivotele=A[high];		//Selecting rightmost element as pivot
	int i=low-1;
	for(int j=low;j<=high-1;j++)		//If element scanned is smaller then it is put on the left of the pivot
	{
		if(A[j]<pivotele)
			{
				i++;			
				swap(&A[j],&A[i]);
				swaps++;
				comp++;
			}
		else
			comp++;
	}
	swap(&A[high],&A[i+1]);			//Pivot is moved to its correct location
	swaps++;
	return i+1;
	
}
void quicksort(int A[],int low,int high)
{
	int pivot;
	if(high>low)
		{
			pivot=partition(A,low,high);		//Two recursive quicksort calls
			quicksort(A,low,pivot-1);
			quicksort(A,pivot+1,high);
		}
}

int main()
{int j=0;
int n=30;
//while(j<4)
{

	struct timeval  tv1, tv2;
	int A[n],i;
	printf("\n");
	int k=n;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		A[i]=k;
		k--;
	}
	print(A,n);
	printf("\n");
	//auto start = high_resolution_clock::now();
	quicksort(A,0,n-1);
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	printf("%d %d %d \n",n,swaps,comp);
	//cout <<duration.count()<< endl;
	print(A,n);
	printf("\n");
	n+=3000;	
	j++;

}
	return 0;
	
}
