#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node* createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void printList(Node *head)
{
    Node *current = head;
    while (current)
    {
        printf("%d -> ", current->data);
        if(current->next == head) break;
        current = current -> next;
    }
    
}

int isCircular(Node *head)
{
    Node *current = head;
    
    while(current)
    {
        if (current -> next == head)
            return 1;
        current = current -> next;
    }
    
    return 0;
}

int main()
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head;
    
    printList(head);
    
    printf("\nIs list circular = %s\n", isCircular(head) ? "yes" : "no");
    
    return 0;
}
