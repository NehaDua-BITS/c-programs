#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int areTreesIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
      return 1;
      
    if (root1 != NULL && root2 != NULL)
    {
      return (root1->data == root2->data) && 
	areTreesIdentical(root1->left, root2->left) && 
	areTreesIdentical(root1->right, root2->right);
    } 
    
    return 0; 
}

int main()
{
  Node *root1 = createNode(1);
  root1->left = createNode(2);
  root1->right = createNode(3);
  root1->left->left = createNode(4);
  root1->left->right = createNode(5);
  root1->right->right = createNode(6);
  root1->right->right->left = createNode(7);
  
  Node *root2 = createNode(1);
  root2->left = createNode(2);
  root2->right = createNode(3);
  root2->left->left = createNode(4);
  root2->left->right = createNode(5);
  root2->right->right = createNode(6);
  root2->right->right->left = createNode(7);
  
  printf("\nAre trees identical : %s", areTreesIdentical(root1, root2) ? "yes" : "no");
  
  return 0;
}
