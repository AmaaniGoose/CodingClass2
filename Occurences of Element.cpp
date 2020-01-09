#include<stdio.h>
int main()
{
int N,i;
scanf("%d",&N);
int A[N];
for(i=0;i<N;i++)
{scanf("%d",&A[i]);
}
int ele,count=0;
scanf("%d",&ele);
for(i=0;i<N;i++)
{
if(A[i]==ele)
{
count++;
}
}
printf("Number of Occurences of %d are : %d",ele,count);
return 0;
}
