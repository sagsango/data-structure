#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct node{
	int data;
	struct node*next;
};
struct node*push_back(struct node*head,int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	if(head==NULL)
	head=new_node;
	else
	{
		struct node*ptr=head;
		while(ptr->next)ptr=ptr->next;
		ptr->next=new_node;
	}
	return head;
}
struct node*push_front(struct node*head,int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=head;
	head=new_node;
	return head;
}
struct node*push_after(struct node*head,int key,int data)
{
	struct node*ptr=head;
	while(ptr&&ptr->data!=key)
	ptr=ptr->next;
	if(ptr)
	{
		struct node*new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->next=ptr->next;
		ptr->next=new_node;
	}
	return head;
}
struct node*push_before(struct node*head,int key,int data)
{
	struct node*ptr=head;
	struct node*preptr=NULL;
	while(ptr&&ptr->data!=key)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr)
	{
		struct node*new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=data;
		new_node->next=ptr;
		if(preptr)
		preptr->next=new_node;
		else
		head=new_node;
	}
	return head;
}
struct node*pop_front(struct node*head)
{
	struct node*ptr=head;
	if(head)
	head=head->next;
	free(ptr);
	return head;
}
struct node*pop_back(struct node*head)
{
	struct node*ptr=head;
	struct node*preptr=NULL;
	while(ptr&&ptr->next)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(preptr)
	preptr->next=NULL;
	else
	head=NULL;
	free(ptr);
	return head;
}
struct node*pop_after(struct node*head,int key)
{
	struct node*ptr=head;
	while(ptr&&ptr->data!=key)
	ptr=ptr->next;
	if(ptr)
	{
		struct node*temp=ptr->next;
		if(ptr->next)
		{
			ptr->next=ptr->next->next;
		}
		free(temp);
	}
	return head;
}
struct node*pop_before(struct node*head,int key)
{
	struct node*ptr=head;
	struct node*preptr=NULL;
	struct node*prepreptr=NULL;
	while(ptr&&ptr->data!=key)
	{
		prepreptr=preptr;
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr)
	{
		if(prepreptr)
		prepreptr->next=ptr;
		if(preptr==head)
		head=head->next;
		free(preptr);
	}
	return head;
}
	
void display(struct node*head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
int node_count(struct node*head)
{
	int c=0;
	while(head)
	{
		c++;
		head=head->next;
	}
	return c;
}
struct node*node_search(struct node*head,int key)
{
	struct node*ptr=head;
	while(ptr&&ptr->data!=key)
	ptr=ptr->next;
	return ptr;
}
struct node*reverse_list(struct node*head)
{
	struct node*ptr=head;
	struct node*preptr=NULL;
	while(ptr)
	{
		struct node*temp=ptr->next;
		ptr->next=preptr;
		preptr=ptr;
		head=ptr;
		ptr=temp;
	}
	return head;
}
struct node*sort_list(struct node*head)
{
	//Its selection sort
	struct node*ptr=head;
	while(ptr)
	{
		struct node*temp=ptr;
		struct node*max_node=ptr;
		while(temp)
		{
			if(temp->data>max_node->data)
			max_node=temp;
			temp=temp->next;
		}
		int td=ptr->data;
		ptr->data=max_node->data;
		max_node->data=td;
		ptr=ptr->next;
	}
	return head;
}
struct node*delete_node(struct node*head,int key)
{
	struct node*ptr=head;
	struct node*preptr=NULL;
	while(ptr&&ptr->data!=key)
	{
		preptr=ptr;
	    ptr=ptr->next;
	}
	if(ptr)
	{
		if(preptr)
		preptr->next=ptr->next;
		else
		head=head->next;
		free(ptr);
	}
	return head;
}
	
int main()
{
	struct node*head=NULL,*ptr=NULL;
	int data,key,option;
	do
	{
		printf("1(push_back) 2(push_front) 3(display) 4(push_after) 5(push_before) 6(pop_front) 7(pop_back) 8(pop after) 9(pop before) 10(node count) 11(node search) 12(reverse list)  13(sort list) 14(delete node):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data to push back:");
			scanf("%d",&data);
			head=push_back(head,data);
			break;
			
			case 2:
			printf("Enter the data for push front:");
			scanf("%d",&data);
			head=push_front(head,data);
			break;
			
			case 3:
			printf("Linked List:");
			display(head);
			break;
			
			case 4:
			printf("Enter the key value for push after:");
			scanf("%d",&key);
			printf("Enter the data value for push after:");
			scanf("%d",&data);
			head=push_after(head,key,data);
			break;
			
			case 5:
			printf("Enter the key value for push before:");
			scanf("%d",&key);
			printf("Enter the data value for push before:");
			scanf("%d",&data);
			head=push_before(head,key,data);
			break;
			
			case 6:
			head=pop_front(head);
			break;
			
			case 7:
			head=pop_back(head);
			break;
			
			case 8:
			printf("Enter the key node for pop after:");
			scanf("%d",&key);
			head=pop_after(head,key);
			break;
			
			case 9:
			printf("Enter the key node for pop before:");
			scanf("%d",&key);
			head=pop_before(head,key);
			break;
			
			case 10:
			printf("Node Count:%d\n",node_count(head));
			break;
			
			case 11:
			printf("Enter the key node for search:");
			scanf("%d",&key);
			ptr=node_search(head,key);
			if(ptr)
			printf("Node Found!!!\n");
			else
			printf("Node Not Found!!!\n");
			break;
			
			case 12:
			head=reverse_list(head);
			break;
			
			case 13:
			head=sort_list(head);
			break;
			
			case 14:
			printf("Enter the key node to delete:");
			scanf("%d",&key);
			head=delete_node(head,key);
			break;
			
			
			
			default:
			if(option!=-1)
			printf("Enter a valid option!!!\n");
			break;
			
		}
	}while(option!=-1);
}

