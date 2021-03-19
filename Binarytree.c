

/*
    Binary Tree
    Implementation using linked list 


*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createnewNode(int data){
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
    
    return newNode;
}

void insertatleft(struct Node* root,int data){

   root->left = createnewNode(data);

}
void insertatright(struct Node* root,int data){
    root->right = createnewNode(data);
}

int main(){
    struct Node* root = createnewNode(1);
    insertatleft(root,2);
    insertatright(root,3);
    insertatleft(root->left,4);
    insertatright(root->right,6);

    printf("Successfully Executed !!");

    return 0;
}