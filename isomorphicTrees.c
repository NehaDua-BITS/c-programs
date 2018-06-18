#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

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

bool areTreesIsomorphic(Node *root1, Node *root2)
{
  if (root1 == NULL && root2 == NULL)
    return true;
    
  if (root1 == NULL || root2 == NULL)
      return false;
      
  if (root1->data != root2->data)
	return false;

  return (areTreesIsomorphic(root1->left, root2->left) && areTreesIsomorphic(root1->right, root2->right)) ||
	  (areTreesIsomorphic(root1->left, root2->right) && areTreesIsomorphic(root1->right, root2->left));
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
  root2->left = createNode(3);
  root2->right = createNode(2);
  root2->left->left = createNode(6);
  root2->right->right = createNode(4);
  root2->right->left = createNode(5);
  root2->left->left->left = createNode(7);
  
  printf("\nAre trees isomorphic : %s", areTreesIsomorphic(root1, root2) ? "yes" : "no");

  return 0;
}
