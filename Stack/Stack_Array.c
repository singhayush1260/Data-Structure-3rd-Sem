#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
int *stack=NULL;
void pop();
void push();
void peek();
void display();
int top=-1;
int n=0;
void main()
{
    printf("Enter the size of stack:");
    scanf("%d",&n);
    stack=calloc(n,sizeof(int));
    int choice=1;
    do
    {
     printf("Press 1: Push\n");
     printf("Press 2: Pop\n");
     printf("Press 3: Peek\n");
     printf("Press 4: Display\n");
     printf("Enter your choice:\n");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1: push();
         break;
         
         case 2: pop();
         break;
         
         case 3: peek();
         break;
         
         case 4: display();
         break;
         default: printf("Invalid Choice.\n");
     }
     printf("\n\nEnter 0 to quit - 1 to continue.\n");
     scanf("%d",&choice);
    } 
    while(choice==1);
    free(stack);
   //getch();
}
void push()
{
    if(top==n-1)
    {
        printf("Stack Overflow.");
    }
    else
    {
    int data=0;
    printf("\nEnter the data:");
    scanf("%d",&data);
    top++;
    stack[top]=data; 
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow.");
    }
    else
    {
     int data=0;
     data=stack[top];
     top--;
     printf("\nPopped data is %d",data);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("\nStack Underflow.");
    }
    else
    {
     printf("Popped data is %d",stack[top]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("\nStack Underflow.");
    }
    else
    {
        for(int i=top;i>-1;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}