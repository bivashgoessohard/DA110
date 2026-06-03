#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct Node *head = NULL;

void createStack(void) {
    head = malloc(sizeof(Node));
    head->data = 0; // size will be stored here
    head->next = NULL;
}

void PUSH(int element) {
    Node *ptr = malloc(sizeof(Node));

    ptr->data = element;
    ptr->next = head->next;
    head->next = ptr;
    head->data++;
}

int POP() {
    if (head->next != NULL) {
        Node *ptr = head->next;
        int element = ptr->data;
        head->next = head->next->next;
        head->data--;
        free(ptr);

        return element;
    } else {
        return -1;
    }
}

int isEmpty() {
    return head == NULL || head->data;
}

int topOfStack() {
    if (head != NULL && head->next != NULL) {
        return head->next->data;
    } else {
        return -1;
    }
}

int sizeOfStack() {
    if (head != NULL) {
        return head->data;
    } else {
        return -1;
    }
}

void display() {
    if (head == NULL) return;

    Node *ptr = head->next;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    createStack();

    PUSH(10);
    PUSH(5);
    PUSH(8);

    display(); // Stack: 8 5 10

    printf("Popped: %d\n", POP()); // Popped: 8

    display(); // Stack: 5 10

    printf("Size: %d\n", sizeOfStack()); // Size: 2

    return 0;
}