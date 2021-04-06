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
  for(int i = 2; i < pos; ++i){
    temp = temp->next;
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

// delete the element at head
void DeleteatHead(){
  if(head == NULL){
    printf("List is Empty \n");
  }
  struct Node* temp = head;
   head = temp->next;
   head->prev = NULL;
  //temp->next = NULL;
  free(temp);
}

void Deleteatanypos(int pos){
  struct Node* temp = head;
  for(int i = 2; i < pos; ++i){
    temp = temp->next;
  }
  struct Node* temp1 = temp->next;
  struct Node* temp2 = temp1->next;
  temp->next = temp1->next;
  temp2->prev = temp1->prev;
  free(temp1);

}
void DeleteatTail(){
  if(head == NULL){
    printf("List is Empty \n");
  }
  struct Node* temp = head;
  while((temp->next)->next != NULL){
    temp = temp->next;
  }
  struct Node* temp1 = temp->next;
  temp->next = NULL;
  free(temp1);
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
  DeleteatHead();
  print();
  DeleteatTail();
  print();
  Deleteatanypos(3);
  print();
  //reverse();

  return 0;
}
