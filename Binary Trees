#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 1000

struct node{
	int data;
	struct node*left;
	struct node*right;
};
struct node*insert(struct node*root,int data)
{
	if(!root)
	{
		struct node*new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->left=NULL;
		new_node->right=NULL;
		root=new_node;
	}
	else
	{
		if(root->data < data)
		root->right=insert(root->right,data);
		else if(root->data > data)
		root->left=insert(root->left,data);
		else 
		printf("Duplicates Not Allowed!!\n");
	}
	return root;
}
void inorder(struct node*root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(struct node*root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node*root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

struct node*Q[SIZE];
int front=0;
int rear=-1;
int isEmpty()
{
	return front>rear;
}
void Enqueue(struct node*ptr)
{
	Q[++rear]=ptr;
}
void Dequeue()
{
	front++;
}
struct node*peek()
{
	return Q[front];
}
void level_order(struct node*root)
{
	Enqueue(root);
	while(!isEmpty())
	{
		if(peek()->left)
		Enqueue(peek()->left);
		if(peek()->right)
		Enqueue(peek()->right);
		printf("%d ",peek()->data);
		Dequeue();
	}
}
struct node*search(struct node*root,int key)
{
	if((!root) || (root->data==key) )
	return root;
	else if(root->data < key)
	return search(root->right,key);
	else
	return search(root->left,key);
}
int node_count(struct node*root)
{
	if(!root)
	return 0;
	else
	return 1+node_count(root->left)+node_count(root->right);
}
int internal_node_count(struct node*root)
{
	if(!root)
	return 0;
	else if(root->left && root->right )
	return 1+internal_node_count(root->left)+internal_node_count(root->right);
	else
	return internal_node_count(root->left)+internal_node_count(root->right);
}
int external_node_count(struct node*root)
{
	if(!root)
	return 0;
	else if(root->left && root->right )
	return external_node_count(root->left)+external_node_count(root->right);
	else
	return 1+internal_node_count(root->left)+internal_node_count(root->right);
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int height(struct node*root)
{
	if(!root)
	return 0;
	else 
	return 1+max(height(root->left),height(root->right));
}
struct node*smallest(struct node*root)
{
	while(root&&root->left)
	root=root->left;
	return root;
}
struct node*largest(struct node*root)
{
	while(root&&root->right)
	root=root->right;
	return root;
}
struct node*mirror_image(struct node*root)
{
	if(root)
	{
		struct node*temp=root->left;
		root->left=root->right;
		root->right=temp;
		root->left=mirror_image(root->left);
		root->right=mirror_image(root->right);
	}
	return root;
}
struct node*delete_node(struct node*root,int key)
{
	if(root==NULL)
	return root;
	else if(root->data < key)
	root->right=delete_node(root->right,key);
	else if(root->data > key)
	root->left=delete_node(root->left,key);
	else
	{
		if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			struct node*temp=largest(root->left);
			root->data=temp->data;
			root->left=delete_node(root->left,temp->data);
		}
	}
}
int main()
{
	int data,key,option;
	struct node*root=NULL;
	struct node*ptr=NULL;
	do
	{
		printf("1(insert node) 2(inorder) 3(preorder) 4(postorder) 5(level order) 6(search) 7(node count) 8(internal_node_count) 9(exteranl_node_count) 10(hight) 11(smallest) 12(largest) 13(mirror image) 14(delete node):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data to insert:");
			scanf("%d",&data);
			root=insert(root,data);
			break;
			
			case 2:
			printf("Inorder:");
			inorder(root);
			printf("\n");
			break;
			
			case 3:
			printf("Preorder:");
			preorder(root);
			printf("\n");
			break;
			
			case 4:
			printf("Postorder:");
			postorder(root);
			printf("\n");
			break;
			
			case 5:
			printf("Levelorder:");
			level_order(root);
			printf("\n");
			
			case 6:
			printf("Enter the key to search:");
			scanf("%d",&key);
			ptr=search(root,key);
			if(ptr)
			printf("Key Found!!!\n");
			else
			printf("Key Node Fund!!!\n");
			break;
			
			case 7:
			printf("Node Count:%d\n",node_count(root));
			break;
			
			case 8:
			printf("Internal Node Count:%d\n",internal_node_count(root));
			break;
			
			case 9:
			printf("External Node Count:%d\n",external_node_count(root));
			break;
			
			case 10:
			printf("Height:%d\n",height(root));
			break;
			
			case 11:
			ptr=smallest(root);
			if(ptr)
			printf("Smallest:%d\n",smallest(root)->data);
			else
			printf("Empty Tree!!!\n");
			break;
			
			case 12:
			ptr=largest(root);
			if(ptr)
			printf("Largest:%d\n",largest(root)->data);
			else
			printf("Empty Tree!!!\n");
			break;
			
			case 13:
			root=mirror_image(root);
			break;
			
			case 14:
			printf("Enter the key node to delete:");
			scanf("%d",&key);
			root=delete_node(root,key);
			break;
			
			default:
			if(option!=-1)
			printf("Enter a valid option!!!\n");
			break;
		}
	}while(option!=-1);
}
	
