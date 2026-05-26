#include <stdio.h>
#include <stdlib.h>


// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Remove duplicate from a single sorted linked list - function
void removeDuplicate(Node *head) {
    if (head == NULL) {
        printf("List is empty!");
        return;
    }

    Node *curr = head;

    while (curr->next != NULL) {
        Node *temp = curr->next;
        if (curr->data == curr->next->data) {
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

// ----- Traverse Function -----//
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


// ------ Main Function --------//

int main(void) {
    size_t n;
    int element;
    printf("Enter number of elements: ");
    if ((scanf("%zu", &n) != 1) || n < 1) {
        printf("Invalid input!\n");
        return 1;
    }

    Node *head, *newNode, *temp;
    head = NULL;

    for (size_t i = 0; i < n; i++) {
        newNode = malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter element %zu: ", i + 1);
        scanf("%d", &element);

        newNode->data = element;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }


    // Traverse List
    traverseList(head);

    // Remove duplicate
    removeDuplicate(head);
    traverseList(head);

    return 0;
}

/*
For removing unsorted linked list I must apply sorting first O(nlogn) time complexity
or I need to implement hashmap for keeping track of the seen element O(n) time complexity
*/