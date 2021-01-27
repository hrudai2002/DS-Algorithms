/* 

Implementing the dequeue using doubly linked list

*/

#include <stdio.h>
#include <stdlib.h>
// Dequeue 
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head;

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
void InsertFront(int x){
    
    struct Node* newNode = GetNewNode(x);
    if(head == NULL){
          head = newNode;
          return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}
void InsertRear(int x){
    struct Node* newNode = GetNewNode(x);
     if(head == NULL){
          head = newNode;
          return;
    }

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;


}
void DeleteFront(){
    if(head == NULL){
        printf("Dequeue is empty \n");
    }

    struct Node* temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);

}
void DeleteRear(){
    if(head == NULL){
        printf("Dequeue is empty \n");
    }

    struct Node* temp = head;
    while((temp->next)->next != NULL){
        temp = temp->next;
    }
    struct Node* temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
}
void print(struct Node* start){
    
    while(start != NULL){
        printf("%d ",start->data);
        start = start->next;
    }
    printf("\n");
}

int main()
{
     head = (struct Node*)malloc(sizeof(struct Node));
     head = NULL;

     InsertFront(10);
     InsertRear(20);
     InsertRear(30);
     InsertRear(40);
     InsertRear(50);
     print(head);
     DeleteFront();
     DeleteRear();
     print(head);

     return 0;



}
