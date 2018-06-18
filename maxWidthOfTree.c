#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a > b) ? a : b)

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

void inorder(Node *root)
{
  if (root)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int getHeight(Node *root)
{
  if(!root)
    return 0;
    
  return 1 + max(getHeight(root->left), getHeight(root->right));  
}

void getMaxWidthRecursive(Node *node, int *count, int level)
{
  if (node)
  {
    count[level]++;
    getMaxWidthRecursive(node->left, count, level+1);
    getMaxWidthRecursive(node->right, count, level+1);
  }
}

int getMaxWidth(Node *root)
{
    int height = getHeight(root);
    printf("\nHeight of tree = %d", height);
    
    int *count = (int *)calloc(height, sizeof(int));
    getMaxWidthRecursive(root, count, 0);
    
    int max = -1;
    for (int i = 0; i < height; i++)
    {
	printf("\nlevel = %d width = %d", i + 1, count[i]);
	if (max < count[i])
	  max = count[i]; 
    }
    
    return max;
}

int main()
{
  Node *root1 = createNode(1);
  root1->left = createNode(2);
  root1->right = createNode(3);
  root1->left->left = createNode(4);
  root1->left->right = createNode(5);
  root1->right->left = createNode(10);
  root1->right->right = createNode(6);
  root1->right->right->left = createNode(7);
  root1->right->right->right = createNode(8);
  
  printf("\nThe tree is :  ");
  inorder(root1);
  
  printf("\nMax width of tree : %d", getMaxWidth(root1));
  
  return 0;
}
