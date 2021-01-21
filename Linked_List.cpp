#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
struct Node* head;
//int size;

// Inserting element in the linked list
void push(int x,int pos){
  if(pos == 1){
    struct Node* temp =  (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    head = temp;
    return;
}
else{

      struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
      temp->data = x;
      temp->next = NULL;
      struct Node* itr = head;
      while(itr->next != NULL){
        itr = itr->next;
      }
      itr->next = temp;
      return;


    }
  }
// Deleting an element in a linked list
void Delete(int pos){

if(pos == 1){
struct Node* temp = head;
struct Node* temp2 = temp->next;
head = temp2->next;
free(temp);
return;

}
return;

}
// Printing elements in iterative manner
void print()
{
  struct Node* temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
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

    push(10,1);
    push(20,2);
    push(30,3);
    push(40,4);
    //pop();

//  Delete(1);
  //print();
  //reverse();
  Rprint(head);
  Rreverse(head);

  return 0;
}
