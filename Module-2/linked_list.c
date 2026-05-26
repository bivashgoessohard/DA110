#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;


//Add funtion: at any point e.g., first, last, n-th position
// Add at first 
void addFirst(Node **head, int element) {
    if (head == NULL)
        return;

    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = element;
    newNode->next = *head;
    *head = newNode;
}

// Add at last
void addLast(Node **head, int element) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failes.\n");
        return;
    }

    newNode->next = NULL;
    newNode->data = element;

    // handle case where empty list is passed
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *ptr = *head;

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
}

// Add k-th Node
void addNode(Node **head, int element, size_t position) {

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // If postition is 1 
    if (position == 1) {
        addFirst(head, element);
        return;
    }

    Node *ptr;
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = element;
    newNode->next = NULL;

    if (*head == NULL) {
        return;
    }

    ptr = *head;

    for (size_t i = 1; i < position - 1; i++) {
        if (ptr == NULL) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}


// ------------Delete operations------------//
// Delete first
void deleteFirst(Node **head) {
    // if head is empty
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete last node
void deleteLast(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Single-node list handle
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *curr = *head;
    Node *prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    int data = curr->data;
    free(curr);
    printf("Deleted %d\n", data);
}

// Delete at any position
void deleteNode(Node **head, size_t position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (*head == NULL) {
        printf("List is empty!");
    }

    Node *curr = *head;

    
    if ((*head)->next == NULL) {
        free(*head);
    } else {
        size_t count = 1;
        while (count < position - 1) {
            curr = curr->next;
            count++;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        
    }
}

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

    // Call add first element function
    addFirst(&head, 0);

    traverse(head);

    // Call add last node
    addLast(&head, 67);

    traverse(head);

    // Add at position 3
    addNode(&head, 7, 3);
    traverse(head);

    // Call delete first Node
    deleteFirst(&head);
    traverse(head);

    // Delete last
    deleteNode(&head, 3);
    traverse(head);
    
    // Free memory
    freeMemory(&head);

    return 0;
}