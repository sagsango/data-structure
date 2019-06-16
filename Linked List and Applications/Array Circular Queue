#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 5
int isFull(int toread,int towrite)
{
	return (towrite+1)%SIZE==toread;
}
int isEmpty(int toread,int towrite)
{
	return toread==towrite;
}
void enqueue(int Q[],int*towrite,int data)
{
	Q[*towrite]=data;
	*towrite=(*towrite+1)%SIZE;
	return;
}
int dequeue(int Q[],int*toread)
{
	int data=Q[*toread];
	*toread=(*toread+1)%SIZE;
	return data;
}
void display(int Q[],int toread,int towrite)
{
	while(toread!=towrite)
	{
		printf("%d ",Q[toread]);
		toread=(toread+1)%SIZE;
	}
	printf("\n");
	return ;
}
		
	
	
int main()
{
	int Q[SIZE],towrite=0,toread=0;
	int option,data;
	do
	{
		printf("1(Enqueue) 2(Dequeue) 3(Display) -1(Exit):");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			if(!isFull(toread,towrite))
			{
			    printf("Enter data to Enqueue:");
			    scanf("%d",&data);
			    enqueue(Q,&towrite,data);
			}
			else
			{
				printf("Queue is FULL !!!\n");
			}
			break;
			
			case 2:
			if(!isEmpty(toread,towrite))
			{
				data=dequeue(Q,&toread);
				printf("Dequeued data:%d\n",data);
			}
			else
			{
				printf("Queue is EMPTY !!!!\n");
			}
			break;
			
			case 3:
			if(!isEmpty(towrite,toread))
			{
				printf("Queue: ");
				display(Q,toread,towrite);
			}
			else
			{
				printf("Queue is EMPTY !!!!\n");
			}
			break;
			
			default:
			if(option!=-1)
			printf("Enter a valid option!!!\n");
			break;
		}
	}while(option!=-1);
}
				
				
	
	
