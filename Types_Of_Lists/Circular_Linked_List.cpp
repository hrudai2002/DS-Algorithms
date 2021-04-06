#include <iostream>
using namespace std;
struct Node{
  int data;
  struct Node* next;
};
struct Node* head;
// Inserting at any position
void insertatpos(int x,int pos){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
    return;
  }
  struct Node* temp = head;
  int count = 2;
  while(count < pos){
    temp = temp->next;
    count++;
  }
  newNode->next = temp->next;
  temp->next = newNode;

}

// Inserting the end
void insertatend(int x){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
    return;
  }
  struct Node* temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = head;
}
// Inserting at the beginning
void insertatbegin(int x){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  if(head == NULL){
    head = newNode;
    newNode->next = head;
    return;
  }

  struct Node* temp = head;
  while(temp->next != head){
    temp = temp->next;
  }

  newNode->next = head;
  head = newNode;
  temp->next = head;
}

// Delelte an element in the list
void Delete(int pos){
  if(head == NULL){
    printf("list is empty\n");
    return;
  }
  if(pos == 1){
    struct Node* t = head;
    struct Node* temp2 = head;
    struct Node* temp3 = temp2->next;
    while(t->next != head){
      t = t->next;
    }
    head = temp3;
    t->next = head;
    temp2->next = NULL;


    free(temp2);
    return;


  }
  int count = 2;
  struct Node*  temp = head;
  while(count < pos){
    count++;
    temp = temp->next;
  }
  struct Node* temp1 = temp->next;
  temp->next = temp1->next;
  temp1->next = NULL;
  free(temp1);

}


// Printing the elements in the list

void print(){
  struct Node* temp = head;
  do{
    printf("%d ",temp->data);
    temp = temp->next;
  }while(temp != head);

  printf("\n");
}


int main()
{
  head = (struct Node*)malloc(sizeof(struct Node));
  head = NULL;
  insertatend(10);
  insertatbegin(20);
  insertatbegin(30);
  insertatend(40);
  insertatend(50);
  insertatend(60);
  print();
  insertatpos(222,5);
  print();
  Delete(5);
  print();
  return 0;
}
