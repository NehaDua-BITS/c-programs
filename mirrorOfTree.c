#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;    
    
    return newNode;
}

void printInorderTraversal(Node *root)
{
    if (root)
    {
	printInorderTraversal(root->left);
	printf("%d ", root->data);
	printInorderTraversal(root->right);
    }
}

void getMirrorOfTree(Node *root)
{
    if (root)
    {
	Node *temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	getMirrorOfTree(root->left);
	getMirrorOfTree(root->right);
    }
}

int main()
{
    Node *root = createNode(50);
    root->left = createNode(40);
    root->right = createNode(30);
    root->left->left = createNode(20);
    root->left->right = createNode(10);
    
    printf("Tree is : \n");
    printInorderTraversal(root);
    
    printf("\n\nMirror of tree is : \n");
    getMirrorOfTree(root);
    printInorderTraversal(root);
    
    
    return 0;
}
