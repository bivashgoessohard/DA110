#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;


//Input funtion: at any point e.g., first, last, n-th position
// TODO Tomorrow

// Reverse operation
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

// Traverse Function
void traverse(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free memory function
void freeMemory(Node **headRef) {
    Node *current = *headRef;
    while(current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

// MAIN FUNCTION
int main(void) {

    size_t n; int value;
    printf("Enter number of elements: ");
    if (scanf("%zu", &n) != 1 || n < 1) {
        printf("Invalid input!\n");
        return 1;
    }
    
    Node *head, *newNode, *temp;

    head = NULL;

    // Input to linked list of n number of elements
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

    // Call traverse function before reversing
    traverse(head);
    
    // Reverse function
    reverseList(&head);

    // Call traverse function after reversing
    traverse(head);
    
    // Free memory
    freeMemory(&head);

    return 0;
}