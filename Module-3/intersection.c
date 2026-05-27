#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Traverse List
void traverseList(Node *head) {
    Node *ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Intersection function
void intersection (Node *head1, Node *head2) {
    while (head1 != NULL) {
        Node *temp = head2;
        while (temp != NULL) {
            if (head1->data == temp->data) {
                printf("Intersection found at %d\n", head1->data);
                return;
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }

    printf("No intersection found!\n");
    
}


// N number of nodes creation
void createNNodes(Node **head, size_t n) {
    *head = NULL;
    Node *temp = NULL;
    Node *newNode;

    int value;

    for (size_t i = 0; i < n; i++) {
        newNode = malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter element %zu: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

int main(void) {
    size_t firstListSize, secondListSize;

    Node *headFirst, *headSecond;

    printf("Enter the number of elements of the 1st List: ");
    if(scanf("%zu", &firstListSize) != 1 || firstListSize < 1) {
        printf("Invalid input!\n");
        return 1;
    }

    createNNodes(&headFirst, firstListSize);


    printf("Enter the number of elements of the 2nd List: ");
    if(scanf("%zu", &secondListSize) != 1 || secondListSize < 1) {
        printf("Invalid input!\n");
        return 1;
    }

    createNNodes(&headSecond, secondListSize);


    traverseList(headFirst);
    traverseList(headSecond);

    intersection(headFirst, headSecond);

    return 0;
}

