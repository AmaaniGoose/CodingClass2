#include<stdio.h>
#include<stdlib.h>
struct Employee{
	int Emp_id;
	char Emp_name[100];
	char Emp_city[100];
};
void swap(struct Employee *a,struct Employee  *b)
{
	struct Employee temp=*a;
	*a=*b;
	*b=temp;
}
struct Employee *CreateDatabase(void)
{int i;
	struct Employee *ptr=(struct Employee*)malloc(2*sizeof(struct Employee));
	for(i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
	{
		scanf("%d",&ptr[i].Emp_id);
		gets(ptr[i].Emp_name);
		gets(ptr[i].Emp_city);
	}
	return ptr;
}
int search(struct Employee *ptr,int Emp_id)
{int i;
	for(i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
	{
		if(Emp_id==ptr[i].Emp_id)
		{return i;
		 break;
		}
	}
}
void sort(struct Employee *ptr)
{int i;
	for(i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
		{	
			if(ptr[i].Emp_id>ptr[i+1].Emp_id)
				{
					swap(&ptr[i],&ptr[i+1]);
				}
		}
	
}
int countemp(struct Employee *ptr)
{
	return sizeof(ptr)/sizeof(ptr[0]);
}
struct Employee *addrec(struct Employee *ptr)
{int org=sizeof(ptr)/sizeof(ptr[0]),i;
	ptr=realloc(ptr,(2+sizeof(ptr))*sizeof(struct Employee));
	for(i=org;i<sizeof(ptr)/sizeof(ptr[0]);i++)
	{
		scanf("%d",&ptr[i].Emp_id);
		gets(ptr[i].Emp_name);
		gets(ptr[i].Emp_city);
	}
	return ptr;
}
void printitem(struct Employee *ptr,int index)
{int i=index;
	printf("%d\n",ptr[i].Emp_id);
	printf("%s\n",ptr[i].Emp_name);
	printf("%s\n",ptr[i].Emp_city);
	
}
void printall(struct Employee *ptr)
{int i;
for(i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
{

	printf("%d\n",ptr[i].Emp_id);
	printf("%s\n",ptr[i].Emp_name);
	printf("%s\n",ptr[i].Emp_city);
}
}

int main()
{

struct Employee *A=CreateDatabase();
int ch,ch2=1;
while(ch2==1)
{

printf("Enter 1 for Searching EMP data using Empid, 2 for Sorting, 3 for counting, 4 for increasing size: ");	
scanf("%d",&ch);
switch(ch)
{
	case 1: int id;
			scanf("%d",&id);
			int index=search(A,id);
			printitem(A,index);
			
	break;
	
	case 2: sort(A);
			printall(A);
	break;
	
	case 3: int count=countemp(A);
			printf("%d",count);
	
	break;
	
	case 4: addrec(A);
			printf("Size successfully increased");
	
	break;
	 
}
printf("Enter more operations? 1 for yes 0 for no");
scanf("%d",&ch2);
}
	
	
}
