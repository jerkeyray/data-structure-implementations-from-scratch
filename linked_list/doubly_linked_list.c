#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(int data) {
  Node* newNode = createNode(data);
  if(head == NULL) {
    head = newNode;
  } else {
   newNode->next = head;
   head->prev = newNode;
  
   head = newNode;
  }
  printf("%d inserted at beginning.\n", data);
}

void insertAtEnd(int data) {
  Node* newNode = createNode(data);
  if(head == NULL) {
    head = newNode;
    return;
  }
  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  printf("%d inserted at end.\n", data);
}

void insertAtPosition(int data, int p) {

  if (p < 1) {
    printf("Invalid Position.\n");
    return;
  }

  if (p == 1) {
    insertAtBeginning(data);
    return;
  }

  Node* newNode = createNode(data);
  Node* temp = head;

  for(int i = 1; i < p - 1 && temp != NULL; ++i) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position %d is out of bounds!\n", p);
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  newNode->prev = temp;
  
  if (temp->next != NULL) {
    temp->next->prev = newNode;
  }

  printf("%d inserted at position %d.\n", data, p);
}

void deleteAtBeginning() {
  if (head == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
  }
  Node* temp = head;
  head = head->next;

  if(head != NULL) {
    head->prev = NULL;
  }

  printf("%d deleted from the beginning.\n", temp->data);
}

void deleteAtEnd() {
  if (head == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
  }

  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }

  if(temp->prev == NULL) {
    head = NULL;
  } else {
    temp->prev->next = NULL;
  }
  
  int deletedData = temp->data;
  free(temp);
  printf("%d deleted from the end.\n", deletedData);
}

void deleteAtPosition(int pos) {
  if (head == NULL || pos < 1) {
      printf("Deletion failed. List is empty or position is invalid.\n");
      return;
  }
  if (pos == 1) {
      deleteAtBeginning();
      return;
  }

  Node* temp = head;
  // Traverse to the node AT the desired position
  for (int i = 1; i < pos && temp != NULL; i++) {
      temp = temp->next;
  }

  if (temp == NULL) {
      printf("Position %d is out of bounds!\n", pos);
      return;
  }

  // Bypass the node to be deleted
  temp->prev->next = temp->next;
  // If it's not the last node
  if (temp->next != NULL) {
      temp->next->prev = temp->prev;
  }
  printf("%d deleted from position %d.\n", temp->data, pos);
  free(temp);
}

void displayList() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  Node* temp = head;
    printf("List (Forward): NULL <- ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
  insertAtEnd(10);
  insertAtEnd(20);
  insertAtEnd(30);
  displayList(); // List (Forward): NULL <- 10 <-> 20 <-> 30 <-> NULL

  insertAtBeginning(5);
  displayList(); // List (Forward): NULL <- 5 <-> 10 <-> 20 <-> 30 <-> NULL

  insertAtPosition(15, 3);
  displayList(); // List (Forward): NULL <- 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

  printf("\n--- Deletions ---\n");
  deleteAtBeginning();
  displayList(); // List (Forward): NULL <- 10 <-> 15 <-> 20 <-> 30 <-> NULL

  deleteAtEnd();
  displayList(); // List (Forward): NULL <- 10 <-> 15 <-> 20 <-> NULL

  deleteAtPosition(2);
  displayList(); // List (Forward): NULL <- 10 <-> 20 <-> NULL

  return 0;
}