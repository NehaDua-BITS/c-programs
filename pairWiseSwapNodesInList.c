#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode -> data = data;
  newNode -> next = NULL;
  
  return newNode;
}

void printList(Node *head)
{
  while(head)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}

void swapPairs(Node **head)
{
  Node *prev = NULL;
  Node *curr = *head;
  
  while (curr && curr->next)
  {
      Node *next = curr->next;
      curr->next = next->next;
      next->next = curr;
      if (prev) prev->next = next;
      
      if (curr == *head)
	*head = next;
	
      prev = curr;
      curr = curr->next;
  }
}

int main()
{
  Node *head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);
  head->next->next->next->next = createNode(5);
  head->next->next->next->next->next = createNode(6);
  
  printf("\nThe list is : ");
  printList(head);
  
  swapPairs(&head);
  printf("\nThe list after swapping is : ");
  printList(head);
  
  return 0;
}
