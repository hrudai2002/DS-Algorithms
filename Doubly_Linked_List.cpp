#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* prev;
  struct Node* next;
};
struct Node* head;


struct Node*  GetNewNode(int x){
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = x;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;

}
// Insert the node at the head
void Insertathead(int x){
  struct Node* NewNode = GetNewNode(x);
  if(head == NULL){
    head = NewNode;
    return;
  }
  head->prev = NewNode;
  NewNode->next = head;
  head = NewNode;
}

// Inert the element at any position
void Insertatany(int x,int pos){
    if(pos == 1){
    Insertathead(x);
  }

  struct Node* NewNode = GetNewNode(x);
  struct Node* temp = head;
  int count = 2;
  while(count != pos){
       temp = temp->next;
       count++;
  }
  struct Node* temp1 = temp->next;
  temp1->prev = NewNode;
  NewNode->next = temp1;
  temp->next = NewNode;
  NewNode->prev = temp;
}

// Insert at end of the list
void Insertatend(int x){
  struct Node* NewNode = GetNewNode(x);
  struct Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = NewNode;
  NewNode->prev = temp;
}
// print the elements in the list
void print(){

  struct Node* temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Reverse the doubly linked list
void reverse(){

  struct Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->prev;
  }
  printf("\n");
}
int main()
{
  head = (struct Node*)malloc(sizeof(struct Node));
  head = NULL;
  Insertathead(10);
  Insertatend(20);
  Insertatend(30);
  Insertatend(40);
  Insertatany(222,2);
  Insertatany(333,3);
  print();
  reverse();

  return 0;
}
