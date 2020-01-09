#include<stdio.h>
#include<stdlib.h>
int main()
{int i,n=10;
int *ptr=(int*)malloc(10*sizeof(int));
if (ptr == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
       
        printf("Memory successfully allocated using malloc.\n"); 
  
    
        for (i = 0; i < n; ++i) { 
            scanf("%d",&ptr[i]);
       } 
  
 
        printf("The elements of the array are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
    } 
  
    return 0; 
} 

