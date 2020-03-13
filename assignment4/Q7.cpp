#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define max 100
int queue[max];
struct node
{
	int data;
	struct node* link;
};
node* getnode(int data) 
{ 

    node* newNode = (node*)malloc(sizeof(node)); 
  	newNode->data = data; 
    newNode->link = NULL; 
    return newNode; 
} 
int size=0;
int IsEmptyqueue()
{
	if(size==0)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int IsFullqueue()
{
	if(size==max)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}
struct node *rear=NULL;
struct node *front=NULL;
void enqueue(int data)
{
	if(IsFullqueue())
	{
		printf("Queue OVERFLOW");
		return;
	}
	struct node* newnode=getnode(data);
	if((rear))
	{
		rear->link=newnode;
	}
	rear=newnode;
	if(!(front))
	{
		front=rear;
	}
	size++;

}

int dequeue()
{struct node* ele=NULL;
	if(IsEmptyqueue())
	{
		printf("UNDERFLOW");
		return INT_MIN;
	}
	ele=front;
	int data=ele->data;
	front=front->link;
	size--;
	free(ele);
	return data;
}



int queuesize()
{
	return size;
}


int main()
{
	int ch,ch1=1,data,dequeueele;
	while(ch1==1)
	{
	printf("Press 1 for enqueue, 2 for dequeue 3 for top element(depricated) 4 for size 5 for checking empty 6 for checking full: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the element to be enqueueed: ");
				scanf("%d",&data);
				enqueue(data);
				
		break;
		
		case 2: dequeueele=dequeue();
				printf("dequeueped element is: %d \n",dequeueele);
		
		break;
				
		case 3: //printf("The top element is %d\n",topele());
		
		break;
		
		case 4: printf("The size is %d\n",queuesize());
		
		break;
		
		case 5: (IsEmptyqueue())?printf("Its empty\n"):printf("Not empty\n");
		
		break;
		
		case 6: (IsFullqueue())?printf("Its full\n"):printf("Not full\n");
	
	}
	printf("Enter more? ");
	scanf("%d",&ch1);
	}
}
