#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createList();
struct Node *insertAtBeginning(struct Node *);
struct Node *insertAtLast(struct Node *);
struct Node *insertAtNth(struct Node *, int);
void printList(struct Node *);
int listSize(struct Node *);
void main()
{
    struct Node *head = createList();
    printList(head);
    // printList(insertAtBeginning(head));
    // insertAtLast(head);
    // printList(head);
    // printf("\nSize= %d ",listSize(head));
    int n;
    printf("\nEnter the position:");
    scanf("%d", &n);
    printList(insertAtNth(head, n));
    getch();
}
struct Node *createList()
{
    int data;
    char continueLoop = 'y';
    struct Node *newNode = NULL;
    struct Node *head = NULL;
    struct Node *temp = NULL;
    while (continueLoop == 'y' || continueLoop == 'Y')
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data:");
        scanf("%d", &data);
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
            temp->next = NULL;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
            temp->next = NULL;
        }
        printf("Do you wish to continue(Y/N):");
        scanf(" %c", &continueLoop);
    }
    return head;
}

int listSize(struct Node *head)
{
    int size = 0;
    if (head == NULL)
        return size;
    while (head != NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}

struct Node *insertAtBeginning(struct Node *head)
{
    int data;
    printf("\nEnter the data to be inserted at beginning:");
    scanf("%d", &data);
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    newHead->data = data;
    newHead->next = head;
    return newHead;
}

struct Node *insertAtLast(struct Node *head)
{
    int data;
    // fflush(stdin);
    printf("\nEnter the data to be inserted at last:");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    return head;
}

struct Node *insertAtNth(struct Node *head, int n)
{
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    if (n > listSize(head))
    {
        newHead = insertAtLast(head);
    }
    else if (n == 1)
    {
        newHead = insertAtBeginning(head);
    }
    else
    {
        newHead = head;
        int c = 2;
        while (head != NULL)
        {
            if (c == n)
            {
                int data;
                printf("\nEnter the data to be inserted:");
                scanf("%d", &data);
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = head->next;
                head->next = newNode;
            }
            head = head->next;
            c++;
        }
    }
    return newHead;
}

void printList(struct Node *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}