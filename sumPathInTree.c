#include <stdio.h>
#include <stdlib.h>

typedef struct node {
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

void inorder(Node *root)
{
  if (root)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int doesSumPathExist(Node *root, int sum)
{
  if (!root)
    return sum == 0;
    
  sum = sum - root->data;
  if (!sum && !root->left && !root->right)
    return 1;
    
  return doesSumPathExist(root->left, sum) || doesSumPathExist(root->right, sum);
}

int main()
{
  Node *root = createNode(10);
  root->left        = createNode(8);
  root->right       = createNode(2);
  root->left->left  = createNode(3);
  root->left->right = createNode(5);
  root->right->left = createNode(2);
  
  printf("\nInorder traversal of tree is : ");
  inorder(root);
  
  int sum = 21;
  printf("\nDoes path exist ? : %s", doesSumPathExist(root, sum) ? "yes" : "no");
  return 0;
}
