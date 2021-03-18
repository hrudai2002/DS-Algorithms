#include <stdio.h>
#include <stdlib.h>

/* Dynamic Stack */
struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;
void push(int);
void pop();
void display();



int main(){
    int ch,n;

   do{
       printf("1. Push \n");
       printf("2. Pop \n");
       printf("3. Display \n");
       printf("4. Exit \n");
       
       scanf("%d",&ch);
       switch(ch){

           case  1: 
            printf("Enter the element \n");
             scanf("%d",&n);
             push(n);
             break;
           case 2:
            pop();
            break;
           case 3:
            display();
           
            
       }
   }while(ch != 4);

   return 0;
}
void push(int data){
    
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;

}
void pop(){

    if(top == NULL){
        printf("Stack is Empty \n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Deleted element is %d \n",temp->data);
    temp->next = NULL;
    free(temp);
}
void display(){

    struct Node* temp = top;
    while(temp != NULL){
        
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
