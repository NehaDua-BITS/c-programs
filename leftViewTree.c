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

void printLeftViewOfTreeRecursive(Node *root, int level, int *maxLevel)
{
  if (!root)
    return;
    
  if (level > *maxLevel)
  {
    printf("%d ", root->data);
    *maxLevel = level;
  }  
  
  printLeftViewOfTreeRecursive(root->left, level +1, maxLevel);
  printLeftViewOfTreeRecursive(root->right, level +1, maxLevel);  
}

void printLeftViewOfTree(Node *root)
{
  int maxLevel = 0;
  printLeftViewOfTreeRecursive(root, 1, &maxLevel);
}

int main()
{
    Node *root = createNode(50);
    root->left = createNode(40);
    root->right = createNode(30);
    //root->left->left = createNode(20);
    root->left->right = createNode(10);
    root->right->right = createNode(60);
    root->right->right->right = createNode(70);
    
    printLeftViewOfTree(root);
    
  return 0;
}
