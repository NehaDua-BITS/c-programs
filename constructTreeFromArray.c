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

void printTree(Node *root)
{
  if (root)
  {
      printf("%d ", root->data);
      printTree(root->left);
      printTree(root->right);
  }
}

void createTreeNode(int *arr, int index, Node **createdArray, Node **root)
{
    Node *node = createdArray[index];
    if (node)  return;
    
    node = createNode(index);
    createdArray[index] = node;
    
    int parent = arr[index];
    if (parent == -1) //if it's root
    {
      *root = node;
      return;
    }
    
    if (!createdArray[parent])
    {
      createTreeNode(arr, parent, createdArray, root);
    }
    
    Node *parentNode = createdArray[parent];
    if (!parentNode->left)
      parentNode->left = node;
    else
	parentNode->right = node;
}

Node *getTreeFromArray(int *arr, int n)
{
  Node **createdArray = (Node **)calloc(n, sizeof(Node *));
  Node *root = NULL;
  
  for (int i = 0; i < n; i++)
  {
    createTreeNode(arr, i, createdArray, &root);
  }
  
  return root;
}

int main()
{
  int arr[] = {1,5,5,2,2,-1,3};
  int length = sizeof(arr) / sizeof(arr[0]);
  
  printf("\nThe no. of elements in array = %d", length);
  
  Node *root = getTreeFromArray(arr, length);
  printf("\nPreorder traversal of tree : ");
  printTree(root);
  
  return 0;
}

