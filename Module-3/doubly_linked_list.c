#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;


// Add node at k-th position
void addNode(Node **head, int element, size_t position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    Node *newNode = malloc(sizeof(Node)); // Memory allocate
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        free(newNode);
        return;
    }

    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node *curr = *head;

    for (size_t i = 1; i < position - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
}


int countNode(Node *head) {
    Node *ptr = head;
    int count = 0;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// Traverse List 
void traverseList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Traverse from tail
void traverseTail(Node *tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");

}

// Free memory function
void freeMemory(Node **headRef) {
    Node *curr = *headRef;

    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    *headRef = NULL;
}

// ----- Main Function ----- //
int main(void) {
    size_t n;
    int value;

    Node *head = NULL;
    Node *tail = NULL;
    Node *temp = NULL;

    printf("Enter the number of elements: ");
    if (scanf("%zu", &n) != 1 || n < 1) {
        printf("Invalid input!\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        Node *newNode = malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter element %zu: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
            tail = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
            tail = temp;
        }
    }

    printf("The list is:\n");
    traverseList(head);
    printf("\n");
    printf("The list from backward is:\n");
    traverseTail(tail);

    addNode(&head, 10, 4);
    traverseList(head);

    int count = countNode(head);
    printf("The number of nodes: %d\n", count);


    // Free memory
    freeMemory(&head);
    tail = NULL;

    return 0;
}