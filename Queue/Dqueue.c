#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
int *queue=NULL;
void enqueueFront();
void enqueueRear();
void dequeueFront();
void dequeueRear();
void display();
int front=-1,rear=-1;
int n=0;
int capacity=0;
void main()
{
    printf("Enter the size of queue:");
    scanf("%d",&n);
    capacity=n-1;
    queue=calloc(n,sizeof(int));
    char choice='y';
    do
    {
     printf("Press 1: Enqueue Front\n");
     printf("Press 2: Enqueue Rear\n");
     printf("Press 3: Dequeue Front\n");
     printf("Press 4: Dequeue Rear\n");
     printf("Press 5: Display\n");
     printf("Enter your choice:\n");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1: enqueueFront();
         break;

         case 2: enqueueRear();
         break;
         
         case 3: dequeueFront();
         break;

         case 4: dequeueRear();
         break;

         case 5: display();
         break;
         default: printf("Invalid Choice.\n");
     }
     fflush(stdin);
     printf("\nEnter N to quit Y to continue.\n");
     scanf("%c",&choice);
    } 
    while(choice=='y'||choice=='Y');
    free(queue);
    getch();
}
void enqueueFront()
{   
    if((front==0&&rear==capacity)||(front==rear+1))
    {
        printf("Queue is full.");
        return;
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
    }
    else if(front==0)
    {
        front=capacity;
    }
    else
    {
    front--;
    }
    int data=0;
    printf("\nEnter the data:");
    scanf("%d",&data);
    queue[front]=data; 
}
void enqueueRear()
{   
    if((front==0&&rear==capacity)||(front==rear+1))
    {
        printf("Queue is full.");
        return;
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
    }
    else if(rear==capacity)
    {
        rear=0;
    }
    else
    {
    rear++;
    }
    int data=0;
    printf("\nEnter the data:");
    scanf("%d",&data);
    queue[rear]=data; 
}
void dequeueFront()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty.");
        return;
    }
    else if(front==rear)
    {
        printf("\nDequed data is %d",queue[front]);
        front=rear=-1;
    }
    else if(front==capacity)
    {
        printf("\nDequed data is %d",queue[front]);
        front=0;
    }
    else
    {
    printf("\nDequed data is %d",queue[front]);
    front++;
    }
     
}

void dequeueRear()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty.");
        return;
    }
    else if(front==rear)
    {
        printf("\nDequed data is %d",queue[rear]);
        front=rear=-1;
    }
    else if(rear==0)
    {
        printf("\nDequed data is %d",queue[rear]);
        rear=capacity;
    }
    else
    {
    printf("\nDequed data is %d",queue[rear]);
    rear--;;
    }
     
}
void display()
{
   if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty.");
    }
    else
    {   
        int i;
        for(i=front;i!=rear;i=(i+1)%n)
        {
            printf("%d ",queue[i]);
        }
        printf("%d ",queue[rear]);
    }
}