#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *reverseList(Node **head) {
    Node *prevNode, *currentNode, *nextNode;

    prevNode = NULL;
    currentNode = *head;
    nextNode = NULL;
    
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    *head = prevNode;

    return *head;
}

int main(void) {

    size_t n; int value;
    printf("Enter number of elements: ");
    if (scanf("%zu", &n) != 1 || n < 1) {
        printf("Invalid input!\n");
        return 1;
    }
    
    Node *head, *newNode, *temp;

    head = NULL;

    for (size_t i = 0; i < n; i++) {
        // Create a node first, allocate memory
        newNode = malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter element %zu: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    Node *current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    Node *newHead = reverseList(&head);

    Node *newCurrent = newHead;
    while(newCurrent != NULL) {
        printf("%d ", newCurrent->data);
        newCurrent = newCurrent->next;
    }
    printf("\n");

    newCurrent = newHead;

    while(newCurrent != NULL) {
        Node *next = newCurrent->next;
        free(newCurrent);
        newCurrent = next;
    }

    return 0;
}