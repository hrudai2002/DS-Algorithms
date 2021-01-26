#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
struct Node* head;

// Inserting the element at the head
void InsertatHead(int x){
  
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
    return;
  }

  newNode->next = head;
  head = newNode;
}

// Inserting the element at any position in the list
void Insertatanyposition(int pos,int x){
  if(pos == 1){
    InsertatHead(x);
    return;
  }
  
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;

  struct Node* temp = head;
  for(int i = 2; i < pos; ++i){
     temp = temp->next;
  }
   newNode->next = temp->next;
   temp->next = newNode;
}


// Inserting the element at the tail in the list
void InsertatTail(int x){

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  if(head == NULL){
    newNode->next = NULL;
    head = newNode;
    return;
  }

  struct Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = NULL;
}

// Deleting the element at the head
void DeleteatHead(){

  struct Node* temp = head;
  head = temp->next;
  free(temp);

  return;
}

// Deleting the element at any position
void Deleteatanyposition(int pos){
  
  struct Node* temp = head;
  for(int i = 2; i < pos; ++i){
     temp = temp->next;
  }
  struct Node* temp1 = temp->next;
  temp->next = temp1->next;
  temp1->next = NULL;
  free(temp1);
}

// Deleting the element at tail
void DeleteatTail(){

  struct Node* temp = head;
  while((temp->next)->next != NULL){
    temp = temp->next;
  }
  struct Node* temp1 = temp->next;
  temp->next = NULL;
  free(temp1);

}

// Printing the elements in the list
void print(struct Node* head){
  

  while(head != NULL){
    printf("%d ", head->data);
    head = head->next;
  }
 
  printf("\n");

}

// Recursive approach to print elements
void Rprint(struct Node* p){

  if(p == NULL){
    return;
  }
  printf("%d ",p->data);
  Rprint(p->next);
}

// Recursive approach to reverse linked list
void Rreverse(struct Node* p){

  if(p == NULL){
    printf("\n");
    return;
  }
  Rreverse(p->next);
  printf("%d ",p->data);
}
// reversing a linked list in iterative method
void reverse()
{
struct Node *prev,*current,*next;
prev = NULL;
current = head;
while(current != NULL){
  next = current->next;
  current->next = prev;
  prev = current;
  current = next;

}
head = prev;
}


int main()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    
    InsertatHead(10);
    InsertatTail(20);
    InsertatTail(30);
    InsertatTail(40);
    InsertatTail(50);
    Insertatanyposition(2,11);


    DeleteatHead();
    DeleteatTail();
    Deleteatanyposition(3);
    print(head);

    return 0;


}