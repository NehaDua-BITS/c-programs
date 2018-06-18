#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  
  return newNode;
}

void printList(Node *head)
{
  while(head)
  {
    printf("%d ", head->data);
    head = head -> next;
  }
}

Node *removeEveryKthNode(Node **head, int k)
{
  int count = 1;
  Node *prev = NULL;
  Node *curr = *head;
  Node *temp = NULL;
  
  while(curr)
  {
    if (count == k)
    {
	if (!prev) {
	  *head = curr->next;
	} else {
	  prev->next = curr->next;
	}
	
	temp = curr;	
	curr = curr -> next;
	free(temp);
	count = 1;
    }
    else
    {
      count++;
      prev = curr;
      curr = curr->next;
    }
  }
  
  return *head;
}

int main()
{
  Node *head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);
  head->next->next->next->next = createNode(5);
  head->next->next->next->next->next = createNode(6);
  
  printf("The list is : ");
  printList(head);
  
  int k;
  printf("\nEnter k : ");
  scanf("%d", &k);
  
  head = removeEveryKthNode(&head, k);
  printf("\nModified List is : ");
  printList(head);
  
  return 0;
}
