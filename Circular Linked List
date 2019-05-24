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
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		struct node*ptr=head;
		while(ptr->next!=head)
		ptr=ptr->next;
		ptr->next=new_node;
	}
	new_node->next=head;
	return head;
}
struct node*push_front(struct node*head,int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	if(head==NULL)
	{
		head=new_node;
		head->next=head;
	}
	else
	{
		struct node*ptr=head;
		while(ptr->next!=head)
		ptr=ptr->next;
		ptr->next=new_node;
		new_node->next=head;
		head=new_node;
	}
	return head;
}
struct node*push_after(struct node*head,int key,int data)
{
	if(head)
	{
	    struct node*ptr=head;
	    do
	    {
		    if(ptr->data==key)
		    break;
		    ptr=ptr->next;
	    }while(ptr!=head);
	    if(ptr->data==key)
	    {
		    struct node*new_node=(struct node*)malloc(sizeof(struct node));
		    new_node->data=data;
		    new_node->next=ptr->next;
		    ptr->next=new_node;
	    }
	}
	return head;
}
struct node*push_before(struct node*head,int key,int data)
{
	if(head)
	{
		struct node*ptr=head->next;
		struct node*preptr=head;
		do
		{
			if(ptr->data==key)
			break;
			else
			{
				preptr=ptr;
				ptr=ptr->next;
			}
		}while(preptr!=head);
		if(ptr->data==key)
		{
			struct node*new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=data;
			new_node->next=ptr;
			preptr->next=new_node;
			if(ptr==head)
			head=new_node;
		}
	}
	return head;
}
struct node*pop_front(struct node*head)
{
	if(head)
	{
		struct node*ptr=head;
		while(ptr->next!=head)
		ptr=ptr->next;
		ptr->next=head->next;
		if(ptr==head)
		head=NULL;
		else
		head=ptr->next;
	}
	return head;
}
struct node*pop_back(struct node*head)
{
	if(head)
	{
		struct node*ptr=head->next;
		struct node*preptr=head;
		while(ptr->next!=head)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==head)
		head=NULL;
		else
		preptr->next=head;
	}
	return head;
}
struct node*pop_after(struct node*head,int key)
{
	if(head)
	{
		struct node*ptr=head;
		do
		{
			if(ptr->data==key)
			break;
			ptr=ptr->next;
		}while(ptr!=head);
		if(ptr->data==key)
		{
			struct node*temp=ptr->next;
			if(ptr==head&&ptr->next==head)
			head=NULL;
			else
			{
				ptr->next=ptr->next->next;
				if(temp==head)
				head=ptr->next;
			}
		}
	}
	return head;
}
struct node*pop_before(struct node*head,int key)
{
	if(head)
	{
		struct node*ptr=head->next->next;
		struct node*preptr=head->next;
		struct node*prepreptr=head;
		do
		{
			if(ptr->data==key)
			break;
			else
			{
				prepreptr=preptr;
				preptr=ptr;
				ptr=ptr->next;
			}
		}while(prepreptr!=head);
		if(ptr->data==key)
		{
			if(ptr==head&&preptr==head)
			head=NULL;
			else
			{
				prepreptr->next=ptr;
				if(preptr==head)
				head=ptr;
			}
		}
	}
	return head;
}
int node_count(struct node*head)
{
	int c=0;
	if(head)
	{
		struct node*ptr=head;
		do
		{
			c++;
			ptr=ptr->next;
		}while(ptr!=head);
	}
	return c;
}
struct node*node_search(struct node*head,int key)
{
	struct node*ptr=head;
	if(head)
	{
		do
		{
			if(ptr->data==key)
			break;
			else
			ptr=ptr->next;
		}while(ptr!=head);
	}
	if(ptr&&ptr->data==key)
	return ptr;
	else
	return NULL;
}
			
struct node*reverse_list(struct node*head)
{
	if(head)
	{
		struct node*htemp=NULL;
		struct node*ptr=head->next;
		struct node*preptr=head;
		do
		{
			struct node*temp=ptr->next;
			ptr->next=preptr;
			htemp=ptr;
			preptr=ptr;
			ptr=temp;
		}while(preptr!=head);
		head=htemp;
	}
	return head;
}
struct node*delete_node(struct node*head,int key)
{
	if(head)
	{
		struct node*ptr=head->next;
		struct node*preptr=head;
		do
		{
			if(ptr->data==key)
			break;
			else
			{
				preptr=ptr;
				ptr=ptr->next;
			}
		}while(preptr!=head);
		if(ptr->data==key)
		{
			if(preptr==ptr)
			head=NULL;
			else
			{
				preptr->next=ptr->next;
				if(ptr==head)
				head=head->next;
			}
		}
	}
	return head;
}	
void display(struct node*head)
{
	if(head)
	{
	    struct node*ptr=head;
	    do
	    {
		    printf("%d ",ptr->data);
		    ptr=ptr->next;
	    }while(ptr!=head);
	}
	printf("\n");
	return ;
}
int main()
{
	struct node*head=NULL,*ptr=NULL;
	int data,option,key;
	do
	{
		printf("1(push_back) 2(display) 3(push_front) 4(push after) 5(push_before) 6(pop_front) 7(pop_back) 8(pop_after) 9(pop before) 10(node count) 11(node search) 12(reverse list) 13(delete_node) -1(Exit):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data for push_back:");
			scanf("%d",&data);
			head=push_back(head,data);
			break;
			
			case 2:
			printf("Circular List:");
			display(head);
			break;
			
			case 3:
			printf("Enter the data for push_front:");
			scanf("%d",&data);
			head=push_front(head,data);
			break;
			
			case 4:
			printf("Enetr the key node for push after:");
			scanf("%d",&key);
			printf("Enter the data for push after:");
			scanf("%d",&data);
			head=push_after(head,key,data);
			break;
			
			case 5:
			printf("Enetr the key node for push before:");
			scanf("%d",&key);
			printf("Enter the data for push before:");
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
			printf("Node count:%d\n",node_count(head));
			break;
			
			case 11:
			printf("Enter the key for search:");
			scanf("%d",&key);
			ptr=node_search(head,key);
			if(ptr)
			{
				printf("Node Found!!!\n");
			}
			else
			{
				printf("Node Node Found!!!\n");
			}
			break;
			
			case 12:
			head=reverse_list(head);
			break;
			
			case 13:
			printf("Enter the node to delete:");
			scanf("%d",&data);
			head=delete_node(head,data);
			break;
			
			default:
			if(option!=-1)
			printf("Enter  a valid option!!!\n");
			break;
		}
	}while(option!=-1);
}
			
	
	
