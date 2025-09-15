#include<stdio.h>

#define MAX_SIZE 100 

// stack struct
typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

// initializer function
void initialize(Stack* s) {
  s->top = -1;
}

// check if stack is empty
int isEmpty(Stack* s) {
  return s->top == -1;
}

// check if stack if full
int isFull(Stack* s) {
  return s->top == MAX_SIZE - 1;
}

// push
void push(Stack* s, int k) {
  if(isFull(s)){
    printf("Error: stack overflow");
  }
  s->arr[++s->top] = k;
  printf("Pushed to stack: %d\n", k);
}

// pop
int pop(Stack* s) {
  if(isEmpty(s)){
    printf("Error: stack underflow\n");
  }
  int k = s->arr[s->top];
  s->top--;
  return k;
}

// peek
int peek(Stack* s) {
  if(isEmpty(s)) {
    printf("Error: stack is empty\n");
  }
  return s->top;
}

int main() {
  Stack stack;
  initialize(&stack);
  push(&stack, 10);
  push(&stack, 20);
  printf("Top element is: %d\n", peek(&stack));

  return 0;
}