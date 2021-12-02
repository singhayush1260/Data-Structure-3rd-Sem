#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
int *queue=NULL;
void enqueue();
void dequeue();
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
     printf("Press 1: Enqueue\n");
     printf("Press 2: Dequeue\n");
     printf("Press 3: Display\n");
     printf("Enter your choice:\n");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1: enqueue();
         break;
         
         case 2: dequeue();
         break;

         case 3: display();
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
void enqueue()
{   
    if(front==-1&&rear==-1)
    {
        front=rear=0;
    }
    else if((rear+1)%n==front)
    {
        printf("Queue is full.");
        return;
    }
    else
    {
     rear=(rear+1)%n;
    }
    int data=0;
    printf("\nEnter the data:");
    scanf("%d",&data);
    queue[rear]=data; 
}
void dequeue()
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
    else
    {
    printf("\nDequed data is %d",queue[front]);
    front=(front+1)%n;
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
        printf("%d ",queue[i]);
    }
}