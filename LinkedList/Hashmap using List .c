#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define mod 10

struct node{
	int data;
	struct node*next;
};
struct node*push_back(struct node*root,int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	if(root==NULL)
	root=new_node;
	else
	{
		struct node*ptr=root;
		while(ptr->next)ptr=ptr->next;
		ptr->next=new_node;
	}
	return root;
}
struct node*search(struct node*root,int data)
{
	while(root&&root->data!=data)
	root=root->next;
	return root;
}
void display(struct node*root)
{
	while(root)
	{
		printf("%d ",root->data);
		root=root->next;
	}
	printf("\n");
	return ;
}
int main()
{
	struct node*v[mod];
	int i,option,data;
	for(i=0;i<10;i++)
	v[i]=NULL;
	
	do
	{
		printf("1(Enter the data) 2(Search the data) 3(display) -1(exit):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data:");
			scanf("%d",&data);
			v[data%mod]=push_back(v[data%mod],data);
			break;
			
			case 2:
			//ptr=search(v[data%mod],data);
			printf("Enter the data:");
			scanf("%d",&data);
			if(search(v[data%mod],data))
			{
				printf("Found!!!!!\n");
			}
			else
			{
				printf("Not Found!!!!!\n");
			}
			break;
			
			case 3:
			printf("HashMap:::::::::::::::::::::::::::\n");
			for(i=0;i<mod;i++)
			{
				printf("Hashkey:%d    Data:",i);
				display(v[i]);
			}
			printf(":::::::::::::::::::::::::::::::::::\n");
			break;
			
			default:
			if(option!=-1)
			printf("Enter a valid option!!!\n");
			break;
		}
	}while(option!=-1);
}
			
	
