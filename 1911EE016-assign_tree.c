#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 100
//DETAILS: Name: Amanullah Asad Roll No: 19/11/EE/016 Branch: ECE
//All 3 questions have been solved in one file and can be accessed using a switch statement
//FUNCTIONS FOR QUEUE
struct node* queue[max];
int front=0;
int rear=max-1;
int size=0;
//Function to reset queue to enable use more than once
void reset()
{
	int i;
	for(i=0;i<max;i++)
	{
		queue[i]=0;
	}
	front=0;
	rear=max-1;
}
//Checks if queue is empty
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
//Checks if queue is full
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
//Insert element in queue
void enqueue(struct node* data)
{
	if(IsFullqueue())
	{
		printf("Queue OVERFLOW");
		return;
	}
	rear=(rear+1)%max;
	queue[rear]=data;
	size++;
}
//Pop element from queue and return it
struct node* dequeue()
{
	if(IsEmptyqueue())
	{
		printf("UNDERFLOW");
	}
	struct node* data=queue[front];
	front=(front+1)%max;
	size--;
	return data;
}
//Returns size of queue
int queuesize()
{
	return size;
}
//Returns front element of queue
struct node* frontele()
{
	return queue[front];
}
//FUNCTIONS FOR QUEUE END

//Defining the basic node
struct node{
	int data;
	struct node* left;
	struct node* right;
};
//Declaring some roots so they don't conflict later
struct node* root;
struct node* rootmirror;
struct node* root1;
struct node* root2;
struct node* root3;
//helper method to return a tree node
struct node* getnode(int data) 
{
	if(data==-1)
	{
		return NULL;
	}
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
//Four standard traversals outlined
void inorder(struct node* root) 
{ 
    if (root == NULL) 
        return; 
    inorder(root->left); 
    printf("%d ", root->data); 
    inorder(root->right); 
}
void preorder(struct node* root) 
{ 
    if (root == NULL) 
        return; 
    printf("%d ", root->data); 
    preorder(root->left); 
    preorder(root->right); 
}
void postorder(struct node* root) 
{ 
    if (root == NULL) 
        return;  
    postorder(root->left); 
    postorder(root->right); 
    printf("%d ", root->data);
}  
void levelorder(struct node* root)
{
	struct node* temp;
	if(!root)
		return;
	enqueue(root);
	while(!IsEmptyqueue())
	{
		temp=dequeue();
		printf("%d ",temp->data);
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
	}
}
//traverals end
void swap(struct node* a, struct node* b)
{
	struct node* temp;
	temp=a;
	a=b;
	b=temp;
}
struct node* create() //Standard creation method for tree
{ 
	int data;
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Give data: (-1 for no data): ");
	scanf("%d",&data);
	if(data==-1)
		return NULL;
	newnode->data=data;
	printf("Enter left child of %d:\n",data);
	newnode->left=create();
 	printf("Enter right child of %d:\n",data);
	newnode->right=create();
	return newnode;	
} 

//Q3.1 The ith element of array has children at positions 2*i+1 and 2*i+2, easier method to create even though it might introduce some ambiguity which os resolved by using -1 when reqd
struct node* createlvlorder(int A[], struct node* root, int i, int n)

{
   if (i < n) {
      struct node* newnode = getnode(A[i]);
      root = newnode;
      if(root==NULL)
      {
      	return root;
	  }
      root->left = createlvlorder(A,root->left,2*i+1,n);
      root->right = createlvlorder(A,root->right,2*i+2,n);
   }
   return root;
} 

//Q1 Recursively mirroring, getting the right nodes of og tree and storing them as left nodes of mirror and vice versa
struct node *mirror(struct node *root)
{

  if (root == NULL)
     return NULL;
  else 
  {

    struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = root->data;
    newnode->left = mirror(root->right);
    newnode->right = mirror(root->left);
	return newnode;
	
  }
}

//Q2 Recursively checking if sum property is true
int checksum(struct node* root)  
{ 
  int left=0,right=0; 
  if(root==NULL||(root->left==NULL&&root->right==NULL)) //Checking if it's null or if it's a leaf root then returning true also acts as base condition
    return 1; 
  else
  { 
	//Assigning data to left and right
    if(root->left != NULL) 
      left=root->left->data; 

    if(root->right != NULL) 
      right = root->right->data; 
  
    if((root->data == left+right)&&checksum(root->left)&&checksum(root->right)) //Recursive check
      return 1; 
    else
      return 0; 
  } 
}

//Q3.2 Getting the level of element recursively, can be done with level order as well
int getlevel(struct node *node, int data, int level)   
{ 
    if (node == NULL) 
       	return -1; 
    if (node->data == data) 
        printf("Element %d found at %d \n",data,level); //Prints all the levels for occurences, even duplicates
    int leftlevel = getlevel(node->left, data, level+1); //Recursviely calling left tree 
    int rightlevel = getlevel(node->right, data, level+1);  //Recursively calling right tree
    if(leftlevel == -1)
            return rightlevel;
    else
            return leftlevel; 
}

//Q3.3 Insertion in level order fashion. Finding first empty node and inserting there
void levelorderinsert(struct node* root,int data)
{
	struct node* temp;
	if(!root)
		return;
	enqueue(root);
	while(!IsEmptyqueue())
	{
		temp=dequeue();
		if(temp->left==NULL)
			{
				temp->left=getnode(data);
				break;
			}
		else
			enqueue(temp->left);
		if(temp->right==NULL)
		{
				temp->right=getnode(data);
				break;
		}
		else
			enqueue(temp->right);
	}
	
}

//Q3.3 Deletion in binary tree. If we are going to preserve complete binary tree property then we should be replacing with the deepest rightmost node. 

void levelorderdelete(struct node* root,int deleteele) 
{ 
	struct node* temp;
	struct node* delnode=NULL;
	struct node* deepnode=NULL;
	int i;
	
	//First part of the code identifies the node to be deleted and the deepest node of the tree
	if(!root)
		return;
	enqueue(root);
	while(!IsEmptyqueue())
	{
		temp=dequeue();
		if(temp->data==deleteele)
		{
			delnode=temp;
		}
		if(temp->left)
			enqueue(temp->left);
			
		if(temp->right)
			enqueue(temp->right);

	}
	deepnode=temp;
	printf("Delete node is %d and deepest rightmost node is %d Switching them now \n",delnode->data,deepnode->data);
	
	//Resetting the queue and now second part of the code places the value of deepest node in temp, deletes it and replaces the node to be deleted with that value
	reset();
	if(delnode!=NULL)
	{	
		int temp2=deepnode->data;
		if(!root)
			return;
		enqueue(root);
		while(!IsEmptyqueue())
		{
			temp=dequeue();
			if(temp==deepnode)
			{
				temp=NULL;
				free(deepnode);
			}
			if(temp->right)
			{
				if(temp->right==deepnode)
				{
					temp->right=NULL;
					free(deepnode);
				}
				else
					enqueue(temp->right);
			}

			if(temp->left)
			{
				if(temp->left==deepnode)
				{
					temp->left=NULL;
					free(deepnode);
				}
				else
					enqueue(temp->left);
			}

		}
		delnode->data=temp2;
	}
	else	
		printf("Element not found \n");
} 


//MAIN FUNCTION FINALLY
int main()
{	
	int ch;
	printf("Enter 1 for q1, 2 for q2 and 3 for q3: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: ;
				int A[]= {8,3,10,1,6,-1,14,-1,-1,4,7,-1,-1,13,-1};
				int n = sizeof(A)/sizeof(A[0]);
				root=createlvlorder(A,root,0,n);
				printf("\n");
				inorder(root);
				printf("\nNow printing the mirror inorder \n ");
				rootmirror=mirror(root);
				inorder(rootmirror);
		break;
		
		case 2: ;
				int A1[]={13,8,5,2,6,5};
				int A2[]={2,0,2,1,0,2,3};
				int n1 = sizeof(A1)/sizeof(A1[0]);
				root1=createlvlorder(A1,root1,0,n1);
				int n2 = sizeof(A2)/sizeof(A2[0]);
				root2=createlvlorder(A2,root2,0,n2);
				printf("Printing inorder of input \n");
				inorder(root1);
				printf("\n");
				inorder(root2);
				printf("\n");
				printf("Results for first array is %d and for second array is %d ",checksum(root1),checksum(root2));
				
		break;
		
		case 3: ;
				int n3,i;
				printf("Input the size of array for level order:  ");
				scanf("%d",&n3);
				int A3[n];
				printf("Enter elements for array: (don't be ambiguous, use -1 to resolve ambiguity if there) ");
				for(i=0;i<n3;i++)
				{
					scanf("%d",&A3[i]);
				}
				root3=createlvlorder(A3,root3,0,n3);
				int ch2;
				printf("Enter 1 for getting four transversals, 2 for finding level of node, 3 for insertion or deletion ");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1: printf("Printing Preorder Transversal ");
							preorder(root3);
							printf("\n");
							printf("Printing Inorder Transversal ");
							inorder(root3);
							printf("\n");
							printf("Printing Postorder Transversal ");
							postorder(root3);
							printf("\n");
							printf("Printing levelorder Transversal ");
							levelorder(root3);
							
					break;
					
					case 2: ;
							int ele;
							printf("Give the element whose level is to be found: ");
							scanf("%d",&ele);
							getlevel(root3,ele,0);
							
					break;
					
					case 3: ;
							int ch3;
							printf("Do you want to insert or delete? 1 for insert and 2 for delete ");
							scanf("%d",&ch3);
							if(ch3==1)
							{	
								int insertele;
								printf("Enter element to be inserted(insertion will be done level order): ");
								scanf("%d",&insertele);
								levelorderinsert(root3,insertele);
								printf("Now printing inorder and postorder to check: ");
								inorder(root3);
								printf("\n");
								postorder(root3);
							}
							else if(ch3==2)
							{
								int deleteele;
								printf("Enter element to be deleted(deletion will preserve CBT property for tree): ");
								scanf("%d",&deleteele);
								levelorderdelete(root3,deleteele);
								printf("Now printing inorder and postorder to check: ");
								inorder(root3);
								printf("\n");
								postorder(root3);
							}
							
					break;
					
					default: printf("Wrong input! ");
				}
				
				
				
	}
	return 0;
}
