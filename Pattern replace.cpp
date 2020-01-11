#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *replacestr(char *str,char *pattern,char *replace)
{
int i,count=0;
int replacelen=strlen(replace);
int patternlen=strlen(pattern);
for(i=0;str[i]!='\0';i++)
{if(strstr(str,pattern)==str)
	{
		count++;
		i+=patternlen-1;
	}
}
char *result=(char*)malloc(i+count*(replacelen-patternlen)+1);
i=0;
while(*str)
{
	if(strstr(str,pattern)==str)
	{
		strcpy(&result[i],replace);
		i+=replacelen;
		str+=patternlen;
	}
	else
		result[i++]=*str++;
}
   result[i] = '\0'; 
    return result; 
} 



int main()
{char str[100],pattern[100],replace[100];
char* result=NULL;
printf("Enter STRING then pattern then replace \n");
gets(str);
gets(pattern);
gets(replace);
result=replacestr(str,pattern,replace);
printf("%s",result);
}
