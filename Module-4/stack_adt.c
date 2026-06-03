#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    int TOP;
    int *A;
    int  MAX;
} Stack;


void initStack(Stack *s, int size) {
    s->TOP = -1;
    s->MAX = size;
    s->A = (int *)malloc(sizeof(int) * size);
}

int PUSH(Stack *s, int element) {
    if(s->TOP < s->MAX - 1) {
        s->TOP++;
        s->A[s->TOP] = element;
        return 1;
    } else {
        return -1;
    }
}

int POP(Stack *s) {
    if(s->TOP > -1) {
        int element = s->A[s->TOP];
        s->TOP--;
        return element;
    } else {
        return -1;
    }
}

int topOfStack(Stack *s) {
    if (s->TOP > -1) {
        return s->A[s->TOP];
    } else {
        return -1;
    }
}

void display(Stack *s) {
    for (int i = 0; i <= s->TOP; i++) {
        printf("%d ", s->A[i]);
    }
    printf("\n");
}

int isEmpty(Stack *s) {
    return (s->TOP == -1);
}

int isFull(Stack *s) {
    return (s->TOP == s->MAX - 1);
}

// Main function to demonstrate stack ADT
int main() {
    Stack b;
    initStack(&b, 100);

    PUSH(&b, 10);
    PUSH(&b, 13);
    PUSH(&b, 5);

    display(&b);

    printf("Popped: %d\n", POP(&b));
    printf("Popped: %d\n", POP(&b));
    printf("Top of stack: %d\n", topOfStack(&b));

    return 0;
}
