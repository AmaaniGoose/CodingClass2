#include<stdio.h>
#include<string.h>
void removeword(char *str,char *word)
{
int i,j,stringlen,wordlen,flag;
stringlen=strlen(str);
wordlen=strlen(word);
for(i=0;i<=stringlen-wordlen;i++)
	
	{	flag=1;
		for(j=0;j<wordlen;j++)
		{if(str[i+j]!=word[j])
		{		
			flag=0;
			break;
			
		}
		
		}
		if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            flag = 0;
        }
        if(flag==1)
        {	
        	for(j=i;j<=stringlen-wordlen;j++)
        	{str[j]=str[j+wordlen];
        	
			}
		stringlen=stringlen-wordlen;
		i--;
		}
	}
}





int main()
{
    char str[100];
    char word[100];
    printf("Enter any string: ");
    gets(str);
    printf("Enter word to remove: ");
    gets(word);

    printf("String before removing '%s' : \n%s", word, str);

    removeword(str, word);

    printf("\n\nString after removing '%s' : \n%s", word, str);

    return 0;
}

