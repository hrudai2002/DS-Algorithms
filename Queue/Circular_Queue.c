/* Circular Queue */

#include <stdio.h>
#include <stdlib.h>
#define size 5
int cq[size];
int front  = -1, rear = -1;
int isFull(){

    if((front == rear + 1) || (front = 0 && rear == size - 1)) return 1;
    else return 0;
}
int isEmpty(){
    if(front == -1) return 1;
    else return 0;
}

void enqueue(int data){

   if(isFull()){
       printf("Queue is Full \n");
       return;
   }

   if(front == -1) front = 0;
   rear = (rear + 1) % size;
   cq[rear] = data;


}
void dequeue(){

    if(isEmpty()){
        printf("Queue is Empty \n");
        return;
    }
    
   if(front == rear){
       front = -1;
       rear = -1;
   }
   else
   front = (front + 1)%size;
}
void display(){
   
   int i;
   for(i = front; i != rear; i = (i + 1)%size)
    printf("%d ",cq[i]);
   printf("%d",cq[i]);
   printf("\n");
}
int main(){
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    dequeue();
    display();
    return 0;

}