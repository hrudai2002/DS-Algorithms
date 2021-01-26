/* 

This is  the code  for tree traversal
-> Preorder
-> Inorder
-> Postorder

if you like give me a ⭐


*/



#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* stack[MAX];
int top = -1;
void push(struct Node* x){

    if(top == MAX - 1){
        printf("Stack is Full");
        printf("\n");
    }
    top = top + 1;
    stack[top] = x;

}
struct Node* pop(){
    struct Node* x;
    if(top == -1){
        printf("Stack Underflow \n");
        exit(0);
    }
    x = stack[top];
    top = top - 1;
    return x;


}
int stack_empty(){

    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Preorder without recursion
void R_Preorder(struct Node* root){
    struct Node* temp = root;
    if(temp == NULL){
        printf("Tree is empty \n");
        return;
    }
    push(temp);

    while(!stack_empty()){
        temp = pop();
        printf("%d ", temp->data);
        if(temp->next != NULL){
            push(temp->next);
        }
        if(temp->prev != NULL){
            push(temp->prev);
        }
    }
    printf("\n");
}

// Preorder with recursion
void Preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    Preorder(root->prev);
    Preorder(root->next);
}

// Inorder without recursion
void R_Inorder(struct Node* root){
        struct Node* temp=root;
 
        if(temp == NULL)
        {
                printf("Tree is empty\n");
                return;
        }
        while(1)
        {
      while(temp->prev!=NULL )
                {
                        push(temp);
                        temp = temp->prev;
                }
 
                while(temp->next == NULL)
                {
                        printf("%d  ",temp->data);
                        if(stack_empty())
                                return;
                        temp = pop();
                }
                printf("%d  ",temp->data);
                temp = temp->next;
        }
        printf("\n");
}


// Inorder with recursion
void Inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    Inorder(root->prev);
    printf("%d ",root->data);
    Inorder(root->next);
}

// Postorder without recursion
void R_Postorder(struct Node* root)
{
        struct Node* temp = root;
        struct Node* x;
 
        if( temp == NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        x = root;
        while(1)
        {
                while(temp->prev != NULL)
                {
                        push(temp);
                        temp =temp->prev;
                }
 
                while( temp->next == NULL || temp->next == x )
                {
                        printf("%d  ",temp->data);
                        x = temp;
                        if( stack_empty() )
                                return;
                        temp = pop();
                }
                push(temp);
                temp = temp->next;
        }
        printf("\n");
}

// Postorder with recursion
void Postorder(struct Node* root){
    if(root == NULL){
        return;
    }
    Postorder(root->prev);
    Postorder(root->next);
    
    printf("%d ",root->data);
}

struct Node* GetNewNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
}
struct Node* Insert(struct Node* root,int data){
    
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->prev = Insert(root->prev,data);
    }
    else{
        root->next = Insert(root->next,data);
    }
    return root;
}
int main()
{
    struct Node* root = NULL;
    int choice;
    int x;
    int ch = 1;
        printf("1.Insert the Element \n");
        printf("2.Traverse by Preorder \n");
        printf("3.Traverse by Preorder without recursion \n");
        printf("4.Traverse by Inorder \n");
        printf("5.Traverse by Inorder without recursion \n");
        printf("6.Traverse by Postorder \n");
        printf("7.Traverse by Postorder without recursion \n");
        printf("8.Exit \n");
        
    while(ch){
       printf("Enter the Choice \n");
       scanf("%d",&choice);
        switch(choice){

            case 1:
              printf("Enter the element \n");
              scanf("%d",&x);
              root = Insert(root,x);
              break;
            case 2:
               Preorder(root);
               printf("\n");
               break;
            case 3:
               R_Preorder(root);
               break;
            
            case 4:
              Inorder(root);
              printf("\n");
              break;
            
            case 5:
               R_Inorder(root);
               break;
            
            case 6:
              Postorder(root);
              printf("\n");
              break;
            
            case 7:
             R_Postorder(root);
             break;
            
            case 8:
             exit(0);
              
                
        }
    }

    return 0;

}
