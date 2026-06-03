#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return head == NULL || head->data == 0;
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


int main(void) {
    const char s[] = "[(3+5)-{(4+8)/2}]";
    createStack();

    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            PUSH(s[i]);
        }
        else if(s[i] == ')') {
            if (isEmpty() || topOfStack() != '(') {
                printf("Syntax error found!\n");
                return 1;
            }
            POP();
        }
        else if(s[i] == '}') {
            if (isEmpty() || topOfStack() != '{') {
                printf("Syntax error found!\n");
                return 1;
            }
            POP();
        }
        else if(s[i] == ']') {
            if (isEmpty() || topOfStack() != '[') {
                printf("Syntax error found!\n");
                return 1;
            }
            POP();
        }
    }
    if(isEmpty()) {
        printf("Parentheses matched.\n");
    } else {
        printf("Sysntax error found.\n");
    }

    while (!isEmpty()) {
        POP();
    }
    free(head);
    head = NULL;

    return 0;
}
