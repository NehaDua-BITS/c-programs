#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

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
	head = head->next;
    }
    
    printf("\n");
}

int findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    
    while (fast && fast->next)
    {
	fast = fast -> next;
	fast = fast -> next;
	slow = slow -> next;
    }
    
    return slow->data;
}

int main()
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("The list is : ");
    printList(head);
    
    printf("The middle of list is = %d", findMiddle(head));
    
    return 0;
}
