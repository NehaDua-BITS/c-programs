#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

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

void getInorderTraversal(Node *root, char *traversal)
{
  if (!root)
  {
    if (strlen(traversal)) 
      strcat(traversal, ";");
    strcat(traversal, "$");
    return;
  }
  
  getInorderTraversal(root->left, traversal);
 
  char str[10];
  sprintf(str, "%d", root->data);
  if (strlen(traversal)) 
    strcat(traversal, ";");
  strcat(traversal, str);

  getInorderTraversal(root->right, traversal);
}

void getPreorderTraversal(Node *root, char *traversal)
{
  if(!root)
  {
    if (strlen(traversal)) 
      strcat(traversal, ";");
    strcat(traversal, "$");
    return;      
  }

  char str[10];
  sprintf(str, "%d", root->data);
  if (strlen(traversal)) 
    strcat(traversal, ";");
  strcat(traversal, str);
         
  getPreorderTraversal(root->left, traversal); 
  getPreorderTraversal(root->right, traversal);
}

int isSubtree(Node *root1, Node *root2)
{
    if (!root2)
      return 1;
    
    if (!root1)
      return 0;
      
    char *inOrderTree1 = (char *)calloc(MAX, sizeof(char));
    getInorderTraversal(root1, inOrderTree1);
    printf("\nInorder traversal of tree 1 : %s", inOrderTree1);
    
    char *inOrderTree2 = (char *)malloc(MAX * sizeof(char));
    getInorderTraversal(root2, inOrderTree2);
    printf("\nInorder traversal of tree 2 : %s", inOrderTree2);

    if (!strstr(inOrderTree1, inOrderTree2))
      return 0;
      
    char *preOrderTree1 = (char *)malloc(MAX * sizeof(char));
    getPreorderTraversal(root1, preOrderTree1);
    printf("\nPreorder traversal of tree 1 : %s", preOrderTree1);
    
    char *preOrderTree2 = (char *)malloc(MAX * sizeof(char));
    getPreorderTraversal(root2, preOrderTree2);
    printf("\nPreorder traversal of tree 2 : %s", preOrderTree2);
    
    return strstr(preOrderTree1, preOrderTree2) != NULL;
}

int main()
{
    Node *root1 = createNode(11);
    root1->left = createNode(12);
    root1->right = createNode(14);
    root1->left->left = createNode(13);
    root1->right->right = createNode(15);
 
    Node *root2 = createNode(12);
    root2->left = createNode(13);
    //root2->left->left = createNode(13);
    //root2->right = createNode(15);
    //root2->right->right = createNode(15);
 
    printf("\n\nIs tree2 subtree of tree1 : %s", isSubtree(root1, root2) ? "yes" : "no");
    
  return 0;
}
