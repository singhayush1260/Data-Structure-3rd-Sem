#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *stack = NULL;
struct node *top = NULL;
void push(int);
void pop();
int peek();
void print(struct node *st);

void main()
{
    char continueLoop = 'y';
    while (continueLoop == 'y' || continueLoop == 'Y')
    {
        printf("   Stack Operations  \n");
        printf("Press 1: Push\n");
        printf("Press 2: Pop\n");
        printf("Press 3: Peek\n");
        printf("Press 4: Display\n");
        int choice, data;
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Top of the stack: %d", peek());
            break;
        case 4:
            print(top);
            break;
        default:
            printf("Invalid choice.");
        }
        printf("\nDo you wish to continue(Y/N): \n");
        fflush(stdin);
        scanf("%c", &continueLoop);
    }
    getch();
    getch();
}
void push(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node *));
    struct node *temp = NULL;
    if (top == NULL)
    {
        newNode->data = data;
        top = newNode;
        top->next = NULL;
    }
    else
    {
        temp = top;
        newNode->data = data;
        top = newNode;
        top->next = temp;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow.");
    }
    else
    {
        int data = top->data;
        printf("Value Popped: %d", data);
        struct node *temp;
        temp = top->next;
        free(top);
        top = temp;
    }
}
int peek()
{
    int data;
    if (top == NULL)
    {
        printf("Stack Underflow.");
        return -1;
    }
    else
    {
        data = top->data;
    }
    return data;
}
void print(struct node *st)
{
    while (st != NULL)
    {
        printf("%d ", st->data);
        st = st->next;
    }
}
