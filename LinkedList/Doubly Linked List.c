#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


struct node{
	int data;
	struct node*prev;
	struct node*next;
};

struct node*push_back(struct node*head,int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	if(head==NULL)
	{
		new_node->next=new_node;
		new_node->prev=new_node;
		head=new_node;
	}
	else
	{
		new_node->next=head;
		new_node->prev=head->prev;
		head->prev->next=new_node;
		head->prev=new_node;
	}
	return head;
}
struct node*push_front(struct node*head,int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	if(!head)
	{
		new_node->next=new_node;
		new_node->prev=new_node;
		head=new_node;
	}
	else
	{
		new_node->next=head;
		new_node->prev=head->prev;
		head->prev->next=new_node;
		head->prev=new_node;
		head=new_node;
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
			else
			ptr=ptr->next;
		}while(ptr!=head);
		if(ptr->data==key)
		{
			struct node*new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=data;
			new_node->next=ptr->next;
			new_node->prev=ptr;
			ptr->next->prev=new_node;
			ptr->next=new_node;
		}
	}
	return head;
}

struct node*push_before(struct node*head,int key,int data)
{
	if(head)
	{
		struct node*ptr=head;
		do
		{
			if(ptr->data==key)
			break;
			else
			ptr=ptr->next;
		}while(ptr!=head);
		if(ptr->data==key)
		{
			struct node*new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=data;
			new_node->next=ptr;
			new_node->prev=ptr->prev;
			ptr->prev->next=new_node;
			ptr->prev=new_node;
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
		if(head->prev==head)
		head=NULL;
		else
		{
			head=head->next;
			ptr->prev->next=head;
			ptr->next->prev=ptr->prev;
		}
		free(ptr);
	}
	return head;
}
struct node*pop_back(struct node*head)
{
	if(head)
	{
		struct node*ptr=head->prev;
		if(head->prev==head)
		head=NULL;
		else
		{
		    ptr->prev->next=head;
		    ptr->next->prev=ptr->prev;
		}
		free(ptr);
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
			else
			ptr=ptr->next;
		}while(ptr!=head);
		if(ptr->data==key)
		{
			if(ptr->next==ptr)
			head=NULL;
			else
			{
				struct node*temp=ptr->next;
				ptr->next->next->prev=ptr;
				ptr->next=ptr->next->next;
				if(temp==head)
				head=head->next;
				free(temp);
			}
		}
	}
	return head;
}
struct node*pop_before(struct node*head,int key)
{
	if(head)
	{
		struct node*ptr=head;
		do
		{
			if(ptr->data==key)
			break;
			else
			ptr=ptr->next;
		}while(ptr!=head);
		if(ptr->data==key)
		{
			if(ptr->next==ptr)
			head=NULL;
			else
			{
				struct node*temp=ptr->prev;
				ptr->prev->prev->next=ptr;
				ptr->prev=ptr->prev->prev;
				if(temp==head)
				head=head->next;
				free(temp);
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
struct node*reverse(struct node*head)
{
	if(head)
	{
		struct node*ptr=head;
		do
		{
			struct node*temp=ptr->next;
			ptr->next=ptr->prev;
			ptr->prev=temp;
			ptr=temp;
		}while(ptr!=head);
		head=head->next;
	}
	return head;
}
		
struct node*sort(struct node*head)
{
	if(head)
	{
		struct node*ptr=head;
		do
		{
			struct node*m_node=ptr;
			struct node*temp=ptr;
			do
			{
				if(temp->data > m_node->data)
				m_node=temp;
				temp=temp->next;
			}while(temp!=head);
			int t_data=m_node->data;
			m_node->data=ptr->data;
			ptr->data=t_data;
			ptr=ptr->next;
		}while(ptr!=head);
	}
	return head;
}
struct node*delete_node(struct node*head,int key)
{
	if(head)
	{
		struct node*ptr=head;
		do
		{
			if(ptr->data==key)
			break;
			else
			ptr=ptr->next;
		}while(ptr!=head);
		if(ptr->data==key)
		{
			if(ptr->next==ptr)
			head=NULL;
			else
			{
				ptr->prev->next=ptr->next;
				ptr->next->prev=ptr->prev;
				if(ptr==head)
				head=head->next;
			}
			free(ptr);
		}
	}
	return head;
}
				

int main()
{
	struct node*head=NULL;
	struct node*ptr=NULL;
	int option,key,data;
	do
	{
		printf("Enter 1(push_back) 2(display) 3(push_front) 4(push_after) 5(push before) 6(pop front) 7(pop back) 8(pop after) 9(pop before) 10(node count) 11(node search) 12(reverse) 13(sort) 14(delete_node) -1(exit):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data to push back:");
			scanf("%d",&data);
			head=push_back(head,data);
			break;
			
			case 2:
			printf("List:");
			display(head);
			break;
			
			case 3:
			printf("Enter the data for push front:");
			scanf("%d",&data);
			head=push_front(head,data);
			break;
			
			case 4:
			printf("Ente the key node for push after:");
			scanf("%d",&key);
			printf("Enter the data for push after:");
			scanf("%d",&data);
			head=push_after(head,key,data);
			break;
			
			case 5:
			printf("Enter the node value for push before:");
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
			printf("Enter the node key for search:");
			scanf("%d",&key);
			ptr=node_search(head,key);
			if(ptr)
			printf("Node %d is present!!!\n",key);
			else
			printf("Node %d is absent!!!\n",key);
			break;
			
			case 12:
			head=reverse(head);
			break;
			
			case 13:
			head=sort(head);
			break;
			
			case 14:
			printf("Enter the key node to delete:");
			scanf("%d",&key);
			head=delete_node(head,key);
			break;
			
			default:
			if(option!=-1)
			printf("Enter a vli option!!!\n");
			break;
		}
	}while(option!=-1);
	return 0;
}
