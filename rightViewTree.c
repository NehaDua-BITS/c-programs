#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;    
    
    return newNode;
}

void printRightViewOfTreeRecursive(Node *root, int level, int *maxLevel)
{
  if (!root)
    return;
    
  if (level > *maxLevel)
  {
    printf("%d ", root->data);
    *maxLevel = level;
  }  
  
  printRightViewOfTreeRecursive(root->right, level +1, maxLevel);  
  printRightViewOfTreeRecursive(root->left, level +1, maxLevel);  
}

void printRightViewOfTree(Node *root)
{
  int maxLevel = 0;
  printRightViewOfTreeRecursive(root, 1, &maxLevel);
}

int main()
{
    Node *root = createNode(50);
    root->left = createNode(40);
    root->right = createNode(30);
    root->left->left = createNode(20);
    root->left->right = createNode(10);
    root->left->left->right = createNode(60);
    //root->right->right->right = createNode(70);
    
    printRightViewOfTree(root);
    
  return 0;
}

