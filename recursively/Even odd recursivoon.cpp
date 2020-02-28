#include<stdio.h>
#include<stdlib.h>
struct node
	 { 
		 int data; 
		 struct node *link;	  	
	 };
struct node *head=(struct node*)malloc(sizeof(node));
int res[100];
static  int i=0;

struct node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 
struct node* traverse(int loc)
{
	struct node* temp=head;
	int count=1;
	while(count!=loc)
	{
		count++;
		temp=temp->link;
	}
	return temp;
	
}
void val()
{
	res[0]=2;
	res[1]=4;
	res[2]=1;
	res[3]=3;
	res[4]=5;
	for(int i=0;i<5;i++)
	{
		printf("%d ",res[i]);
	}
}

  
struct node* list(struct node* head,int data)
{
if(head==NULL)
	{
		return getnode(data);
	}
else
	{	

	head->link=list(head->link,data);
	
	}
return head;
}

void printall(struct node* head) 
{ 
    if (head == NULL) 
       return; 
	    
    printf("%d->",head->data);
  
 	printall(head->link); 
} 

void rearrangedataeve(struct node* head)
{
	
if(head->link==NULL)
	{
	if((head->data)%2==0)
	{
		res[i]=head->data;
		i++;
	}
	return;
	}
else
	{
		if((head->data)%2==0)
		{	
			res[i]=head->data;
			i++;
		}
		rearrangedataeve(head->link);
	}


}

void rearrangedataodd(struct node* head)
{
	
if(head->link==NULL)
	{
	if((head->data)%2!=0)
	{
		res[i]=head->data;
		i++;
	}
		return;
	}
else
	{
		if((head->data)%2!=0)
		{	
			res[i]=head->data;
			i++;
		}
		rearrangedataodd(head->link);
	}


}

void rearrange(int n)
{	
	
	int i;
	struct node *temp,*newnode;
	free(head);
	head=(struct node*)malloc(sizeof(node));
	head->data=res[0];
	head->link=NULL;
	temp=head;
	for(i=1;i<n;i++)
	{
		newnode=getnode(res[i]);
		temp->link=newnode;
		temp=temp->link;
	}
	val();
}

int main()
{
	int n,i;
	head=NULL;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int data;
		printf("Enter data for node %d : ",i+1);
		scanf("%d",&data);
		head=list(head,data);
	}
	printall(head);
	printf("\n");
	rearrangedataeve(head);
	rearrangedataeve(head);
	rearrange(n);
	//printall(head);
	return 0;
}
