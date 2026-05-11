#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main(void) {

    int n;

    struct Node *head = NULL, *newNode = NULL, *temp = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        newNode = malloc(sizeof(struct Node));

        printf("Enter element %d: ", i + 1);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print after all nodes created
    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");

    // Free after printing
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}