 #include<stdio.h>
#include <sys/time.h>
#include<stdlib.h>
//#include <chrono> 
//#include <iostream>
//using namespace std;
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
void merge(int A[],int beg,int mid,int end) //Merge sort code
{
    int i, j, k; 
    int n1 = mid - beg + 1; 
    int n2 =  end - mid; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 		//Storing data in Aux arrays
        L[i] = A[beg + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = A[mid + 1+ j]; 
    i = 0; 
    j = 0; 
    k = beg;  
    while (i < n1 && j < n2) 		//Comparing data of aux arrays and putting it in main array in sorted order
    { 
        if (L[i] <= R[j]) 
        { 
            A[k] = L[i]; 
            i++; 
 
        } 
        else
        { 
            A[k] = R[j]; 
            j++; 
        } 
        k++; 
        swaps++;			
        comp++;
    } 
    while (i < n1) 			//Copying the rest of the array when one of them is empty
    { 
        A[k] = L[i]; 
        i++; 
        k++; 
        swaps++;
    } 
    while (j < n2) 			//Copying the rest of the data
    { 
        A[k] = R[j]; 
        j++; 
        k++; 
        swaps++;
    } 
}
void mergesort (int A[],int beg,int end)
   {
        if( beg < end ) {
        int mid = (beg + end ) / 2 ;          
        mergesort (A, beg , mid ) ;                //Two recursive mergesort calls
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
	int k=0;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		A[i]=rand();
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
