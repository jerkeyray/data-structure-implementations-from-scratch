#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // max size of queue

typedef struct {
  int items[MAX_SIZE];
  int front; 
  int rear;
} Queue;

void init(Queue* q) {
  q->front = -1;
  q->rear = -1;
}

int isFull(Queue* q) {
  return ((q->rear + 1) % MAX_SIZE == q->front);
}

int isEmpty(Queue* q) {
  return (q->front == -1);
}

void enqueue(Queue* q, int value) {
  if (isFull(q)) {
    printf("Error: queue is full.\n");
    return;
  }

  if (isEmpty(q)) {
    q->front = 0;
  }

  q->rear = (q->rear + 1) % MAX_SIZE;
  q->items[q->rear] = value;
  printf("%d has been enqueued.\n", value);
}

void dequeue(Queue* q) {
  if (isEmpty(q)) {
    printf("Error: queue is empty (underflow).\n");
  }

  int element = q->items[q->front];

  if (q->front == q->rear) {
    init(q);
  } else {
    q->front = (q->front + 1) % MAX_SIZE;
  }
  printf("%d has been dequeued.\n", element);
}

void display(Queue* q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Queue: [ ");
  int i;
  for (int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
    printf("%d, ", q->items[i]);
  }
  printf("%d ]", q->items[i]);
}

// main now declares and initializes a queue variable
int main() {
    // 1. Declare an instance of the CircularQueue
  Queue myQueue;
    
    // 2. Initialize it
    init(&myQueue);
    
    // 3. Pass its address to the functions
    printf("--- Struct-based Circular Queue ---\n");
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    display(&myQueue);

    dequeue(&myQueue);
    display(&myQueue);
    
    return 0;
}