#include<stdio.h>
#include<stdbool.h>
void countFreq(int arr[], int n) 
{ 
int i;
bool visited[n];
for(i=0;i<n;i++)
{	
	visited[i]=false;
}
 
    for (int i = 0; i < n; i++) { 
  
        if (visited[i] == true) 
            continue; 
  
        int count = 1; 
        for (int j = i + 1; j < n; j++) 
		{ 
            if (arr[i] == arr[j]) { 
                visited[j] = true; 
                count++; 
            } 
        } 
        printf("%d -> %d\n",arr[i],count);
    
    } 
} 
  
int main() 
{ 
   int n;
scanf("%d\n",&n);
int A[n];
for(int i=0;i<n;i++)
{A[i]=0;
}
for(int i=0;i<n;i++)
{scanf("%d",&A[i]);
}
    countFreq(A, n); 
    return 0; 
} 
