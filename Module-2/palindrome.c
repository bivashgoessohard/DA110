/*
Flawed method, does not work for leading zero and may happen integer overflow for bigger digits
Has to use slow and fast pointer method for linear time complexity
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Reverse function
void reverseList(Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Conver list to digit function
int convertToDigit(Node *head) {
    int digit = 0;

    while (head != NULL) {
        digit = (digit * 10) + head->data;
        head = head->next;
    }

    return digit;
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


// ------- Main Function ------- //
int main(void) {
    size_t n;
    int value;

    Node *head = NULL;
    Node *temp, *newNode;

    // Take input of number of list elements
    printf("Enter the number of elements: ");
    if (scanf("%zu", &n) != 1 || n < 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Take input of n elements and create singly linked list
    for (size_t i = 0; i < n; i++) {
        newNode = malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter value %zu: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    traverseList(head);

    // Convert to digit
    int digit_before_reverse = convertToDigit(head);
    printf("%d\n", digit_before_reverse);


    // Reverse List
    reverseList(&head);
    traverseList(head);

    int digit_after_reverse = convertToDigit(head);
    printf("%d\n", digit_after_reverse);

    if (digit_before_reverse == digit_after_reverse) {
        printf("Palindrome.\n");
    } else {
        printf("Not palindrome!\n");
    }

    return 0;
}