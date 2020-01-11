#include<stdio.h>
#include<stdlib.h>
struct Employee{
	int Emp_id;
	char Emp_name[100];
	char Emp_city[100];
}ptr[100]={0};
int n=5;
void swap(struct Employee *a,struct Employee  *b)
{
	struct Employee temp=*a;
	*a=*b;
	*b=temp;
}
void CreateDatabase(void)
{int i;

printf("Enter data: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ptr[i].Emp_id);
		scanf("%s",ptr[i].Emp_name);
		scanf("%s",ptr[i].Emp_city);
	}
printf("Database created with size %d\n",n);
}
int search(struct Employee *ptr,int Emp_id)
{int i;
	for(i=0;i<n;i++)
	{
		if(Emp_id==ptr[i].Emp_id)
		{return i;
		 break;
		}
	}
}
void sort(struct Employee *ptr)
{int i;
	for(i=0;i<n;i++)
		{	
			if(ptr[i].Emp_id>ptr[i+1].Emp_id)
				{
					swap(&ptr[i],&ptr[i+1]);
				}
		}
	
}
int countemp(struct Employee *ptr)
{
	return n;
}
void addrec(struct Employee *ptr)
{int old=n,i;
n=old+5;
printf("Enter data: \n");
	for(i=old;i<n;i++)
	{
		scanf("%d",&ptr[i].Emp_id);
		gets(ptr[i].Emp_name);
		gets(ptr[i].Emp_city);
	}
printf("Database expanded with size %d\n",n);
}


void printitem(struct Employee *ptr,int index)
{int i=index;
	printf("%d\n",ptr[i].Emp_id);
	printf("%s\n",ptr[i].Emp_name);
	printf("%s\n",ptr[i].Emp_city);
	
}
void printall(struct Employee *ptr)
{int i;
for(i=0;i<n;i++)
{

	printf("%d\n",ptr[i].Emp_id);
	printf("%s\n",ptr[i].Emp_name);
	printf("%s\n",ptr[i].Emp_city);
}
}

int main()
{int index,id,count;
CreateDatabase();
int ch,ch2=1;
while(ch2==1)
{

printf("Enter 1 for Searching EMP data using Empid, 2 for Sorting, 3 for counting, 4 for increasing size: ");	
scanf("%d",&ch);
switch(ch)
{
	case 1: printf("Enter emp id to search: ");
			scanf("%d",&id);
			index=search(ptr,id);
			printitem(ptr,index);
			
	break;
	
	case 2: sort(ptr);
			printall(ptr);
	break;
	
	case 3: count=countemp(ptr);
			printf("%d",count);
	
	break;
	
	case 4: addrec(ptr);
			printf("Size successfully increased\n");
	
	break;
	 
}
printf("\nEnter more operations? 1 for yes 0 for no: ");
scanf("%d",&ch2);
}
	
	
}
