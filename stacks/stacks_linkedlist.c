#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// node struct 
typedef struct Node {
  int val;
  struct Node* next;
} Node;

// stack struct
typedef struct {
  Node* top;
} Stack;

// initializer function
void initialize(Stack* s) {
  s->top = NULL;
}

// isEmpty function
int isEmpty(Stack* s) {
  return s->top == NULL;
}

// push 
void push(Stack* s, int k) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error: memory allocation failed\n");
    return;
  }
  newNode->val = k;
  newNode->next = s->top;
  s->top = newNode;
  printf("Pushed to stack: %d", k);
}

// pop
int pop(Stack* s) {
  if (s->top == NULL) {
    printf("Error: stack underflow\n");
    return INT_MIN;
  }
  Node* temp = s->top;
  int poppedValue = temp->val;
  s->top = s->top->next;
  free(temp);
  return poppedValue;
}

// peek
int peek(Stack* s) {
  if (s->top == NULL) {
    printf("Error: stack is empty\n");
    return INT_MIN;
  }
  return s->top->val;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack));

    printf("%d popped from stack.\n", pop(&stack));
    printf("%d popped from stack.\n", pop(&stack));

    printf("Top element after pop operations is: %d\n", peek(&stack));

    push(&stack, 40);

    printf("Top element after new push is: %d\n", peek(&stack));

    return 0;
}

