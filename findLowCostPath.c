#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
  
/* A tree node has key, pointer to its parent and pointers to its child */
typedef struct node node;   
struct node
{
  int cost;
  int numOfChildren;
  node **children;
  node *parent;
};
 
void getCheapestCostRecursive(node *root, int currentPathCost, int *min)
{
  int cost = root->cost + currentPathCost;
  if (!root->numOfChildren) //leaf node
  {
    if (cost < *min)
      *min = cost;
    return;
  }
  
  for (int i = 0; i < root->numOfChildren; i++)
  {
    getCheapestCostRecursive(root->children[i], cost, min);
  }
}

int getCheapestCost(node *rootNode)
{
  // your code goes here
  int min = INT_MAX;
 
  getCheapestCostRecursive(rootNode, 0, &min);
  
  return min;
}

/******************************************
 * Use the helper code below to implement *
 * and test your function above           *
 ******************************************/ 
 
// Helper function that allocates a new node 
node* newNode(int cost, int numOfChildren, node *parent)
{
  node* n = (node*) malloc(sizeof(node));
  n->cost   = cost;
  n->numOfChildren   = numOfChildren;
  n->children   =  (node **)malloc(sizeof(node *) * numOfChildren);
  n->parent = parent;
   
  return(n);
}
  
/*********************************************
 * Driver program to test above function     *
 *********************************************/ 
 
int main()
{
  node *root = newNode(0, 3, NULL);
  //root->numOfChildren = 3;
  root->children[0] = newNode(5, 1, root);
  root->children[1] = newNode(3, 2, root);
  root->children[2] = newNode(12, 0, root);
  
  root->children[0]->children[0] = newNode(4, 0, root->children[0]);
  
  root->children[1]->children[0] = newNode(2, 1, root->children[1]);
  root->children[1]->children[1] = newNode(0, 1, root->children[1]);
  
  root->children[1]->children[0]->children[0] = newNode(1, 0, root->children[1]->children[0]);
  
  root->children[1]->children[1]->children[0] = newNode(10, 0, root->children[1]->children[1]);
  
  
  
    
  int cost = getCheapestCost(root);
  printf("%d", cost);
  
  return 0;
}
