#include <stdio.h>
#include <stdlib.h>

// define struct for each node
typedef struct Node{
  int data; 
  struct Node* next;
} Node;

Node* head = NULL; // global head pointer

Node* createNode(int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Error: memory allocation failed\n");
    exit(1);
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(int value) {
  Node* newNode = createNode(value);
  newNode->next = head;
  head = newNode;
}

void insertAtEnd(int value) {
  Node* newNode = createNode(value);

  if(head == NULL) {
    head = newNode;
    return;
  }

  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}
 
void displayList() {
  if (head == NULL) {
    printf("List is empty.\n");
  }
  Node* temp = head;
  while(temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    displayList(); // Output: Linked List: 5 -> 10 -> 20 -> NULL
    return 0;
}
