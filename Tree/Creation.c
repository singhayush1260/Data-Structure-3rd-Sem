#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create();
void preOrder(struct Node*);
void main()
{
    struct Node* root=create();
    printf("Preorder Traversal:\n");
    preOrder(root);
    printf("Postorder Traversal:\n");
    postOrder(root);
    printf("Inorder Traversal:\n");
    inOrder(root);
    getch();
}
struct Node* create()
{
    int x=0;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
    printf("\nEnter the data(Enter -1 to exit)");
    scanf("%d",&x);
    if(x==-1)
    return 0;
    newNode->data=x;
    printf("\nEnter the left child of %d ",x);
    newNode->left=create();
    printf("\nEnter the right child of %d ",x);
    newNode->right=create();
}
void preOrder(struct Node* root)
{
  if(root== NULL)
  return;
  printf("%d ",root->data);
  preOrder(root->left);
  preOrder(root->right);
}
void postOrder(struct Node* root)
{
  if(root== NULL)
  return;
  preOrder(root->left);
  preOrder(root->right);
  printf("%d ",root->data);
}
void inOrder(struct Node* root)
{
  if(root== NULL)
  return;
  preOrder(root->left);
  printf("%d ",root->data);
  preOrder(root->right);
}