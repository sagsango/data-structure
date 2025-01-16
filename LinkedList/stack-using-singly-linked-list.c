#include <stdio.h>
#include <stdlib.h>

// Define a stack node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Push an element onto the stack
void push(Node **top, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop an element from the stack
int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node *temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Peek the top element
int peek(Node *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Check if the stack is empty
int isEmpty(Node *top) {
    return top == NULL;
}

int main() {
    Node *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(stack));

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    if (isEmpty(stack))
        printf("Stack is empty now.\n");

    return 0;
}
