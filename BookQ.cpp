#include<stdio.h>
#include<stdlib.h>

struct Book{
	int price;
	int pages;
	int sold;
	char name[100];
};
void swap(struct Book *a,struct Book *b)
{
	struct Book temp=*a;
	*a=*b;
	*b=temp;
}
void CreateDatabase(struct Book ptr[],int n)
{int i;
printf("Enter data price pages sold and name respectively: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ptr[i].price);
		scanf("%d",&ptr[i].pages);
		scanf("%d",&ptr[i].sold);
		scanf("%s",ptr[i].name);
	
	}
printf("Database created with size %d\n",n);
}
void printall(struct Book ptr[],int n)
{int i;
for(i=0;i<n;i++)
{

	printf("Price: %d\n",ptr[i].price);
	printf("Pages: %d\n",ptr[i].pages);
	printf("Sold: %d\n",ptr[i].sold);
	printf("Name: %s\n\n",ptr[i].name);
}
}
void sortpage(struct Book ptr[],int n)
{int i;
	for(i=0;i<n;i++)
		{	
			if(ptr[i].pages>ptr[i+1].pages)
				{
					swap(&ptr[i],&ptr[i+1]);
				}
		}
		printf("Book %s has max pages i.e %d\n",ptr[n-1].name,ptr[n-1].pages);
}
void sortprice(struct Book ptr[],int n)
{int i;
	for(i=0;i<n;i++)
		{	
			if(ptr[i].price>ptr[i+1].price)
				{
					swap(&ptr[i],&ptr[i+1]);
				}
		}
		printf("Book %s has min price i.e %d\n",ptr[0].name,ptr[0].price);
}
void earning(struct Book ptr[],int n)
{int income,i;
	for(i=0;i<n;i++)
	{
		income+=ptr[i].price*ptr[i].sold;
	
	}
printf("%d",income);
}

int main()
{int n;
printf("Enter the number of entries: ");
scanf("%d",&n);
struct Book A[n];
CreateDatabase(A,n);
int ch,ch2=1;
while(ch2==1)
{

printf("Enter 1 for PRINTING, 2 for MAXPAGES, 3 for MINCOST, 4 for INCOME: ");	
scanf("%d",&ch);
switch(ch)
{
	case 1: printall(A,n); 
			printf("\n");
			
	break;
	
	case 2:	sortpage(A,n);
			printf("\n");
	break;
	
	case 3: sortprice(A,n);
			printf("\n");
	break;
	
	case 4: earning(A,n);
			printf("\n");
	
	break;
	 
}
printf("\nEnter more operations? 1 for yes 0 for no: ");
scanf("%d",&ch2);
}
	
	
}
