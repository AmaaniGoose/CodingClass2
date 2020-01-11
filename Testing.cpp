#include<stdio.h>
#include<stdlib.h>
struct Employee{
	int Emp_id;
	char Emp_name[100];
	char Emp_city[100];
}*ptr=(struct Employee*)malloc(10*sizeof(struct Employee));

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
{printf("%d",(sizeof(ptr)/sizeof(ptr[0])));
if(ptr==NULL)
{printf("NO");
}
else
printf("YES");
}
