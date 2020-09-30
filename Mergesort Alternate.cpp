 #include<stdio.h>
#include <sys/time.h>
#include<stdlib.h>
//#include <chrono> 
#include <iostream>
using namespace std;
//using namespace std::chrono;
int comp=0;
int swaps=0;
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
void merge(int A[],int beg,int mid,int end) 
{
int p = beg ,q = mid+1;

int	temp[end-beg+1] , k=0;

for(int i = beg ;i <= end ;i++) 
{
	if(p>mid)  
	{
	      
       temp[k++]=A[q++];
        comp++;
        swaps++;
	}
    else if (q>end)  
	{
	  
       temp[k++]=A[p++];
        comp++;
        swaps++;
	}
	
    else if(A[p]<A[q])     
    {
	   temp[k++]=A[p++];
	    comp++;
	    swaps++;
	}
    else
      temp[k++]=A[q++];
      comp++;
      swaps++;
      
 }
  for (int p=0;p<k;p++) {
     A[beg++] = temp[p];  
     swaps++;
     }

}
void mergesort (int A[],int beg,int end)
   {
        if( beg < end ) {
        int mid = (beg + end ) / 2 ;          
        mergesort (A, beg , mid ) ;                
        mergesort (A,mid+1 , end ) ;             
        merge(A,beg , mid , end );   
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
	//srand(time(0));
	for(i=0;i<n;i++)
	{
		A[i]=k;
		k--;
	}
	print(A,n);
	printf("\n");
	//auto start = high_resolution_clock::now();
	mergesort(A,0,n-1);
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	printf("%d %d \n",swaps,comp);
	//cout <<duration.count()<< endl;
	print(A,n);
	printf("\n");
	n+=30000;	
	j++;

}
	return 0;
	
}
