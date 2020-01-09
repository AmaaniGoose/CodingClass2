#include<stdio.h>
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void reverse(int A[],int n)
{int *beg=A;
int *end=A+n-1;
while(beg<end)
{swap(beg,end);
beg++;
end--;
}
}

int main()
{

int n;
scanf("%d",&n);
int A[n];
for(int i=0;i<n;i++)
{
	scanf("%d",&A[i]);
}
printf("Original array is: \n");
for(int i=0;i<n;i++)
{
	printf("%d ",A[i]);
}
reverse(A,n);
printf("\n Reversed array is: \n");
for(int i=0;i<n;i++)
{
	printf("%d ",A[i]);
}


}
