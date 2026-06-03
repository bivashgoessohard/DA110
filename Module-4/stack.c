#include <stdio.h>
#define MAX 100

int stack[MAX];
int TOP = -1;


// Push into stack
int PUSH(int element) {
    if(TOP < MAX - 1) {
        TOP++;
        stack[TOP] = element;
        return 1;
    } else {
        return -1; // Stack overflow
    }
}

// POP operation
int POP() {
    if(TOP > -1) {
        int element = stack[TOP];
        TOP--;
        return element;
    } else {
        return -1; // Stack is empty / underflow
    }
}

// Display operation
void display() {
    for(int i = 0; i <= TOP; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Top of stack
int topOfStack() {
    return stack[TOP];
}

// Is empty
int isEmpty() {
    return (TOP == -1);
}

int isfull() {
    return (TOP == MAX - 1);
}

int main(void) {
    PUSH(10);
    PUSH(12);
    PUSH(19);

    printf("%d\n", POP());
    display();
    printf("%d\n", topOfStack());

    return 0;
}