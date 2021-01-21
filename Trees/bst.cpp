// Binary search tree
#include <stdio.h>
#include <stdlib.h>

struct BstNode{
  int data;
  struct BstNode* left;
  struct BstNode* right;
};
struct BstNode* GetNewNode(int data){
  struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
  newNode->data = data;
  newNode->right = newNode->left = NULL;

  return newNode;
}
struct BstNode* Insert(struct BstNode* root,int data){
  if(root == NULL){
    root = GetNewNode(data);
    }

  else if(data <= root->data){
        root->left = Insert(root->left,data);
  }
  else{
    root->right = Insert(root->right,data);
  }
  return root;
}
int search(struct BstNode* root,int data){
  if(root == NULL){
    return 0;
  }
  else if(root->data == data){
    return 1;
  }
  else if(data <= root->data){
    return search(root->left,data);
  }
  else{
    return search(root->right,data);
  }
}


int  main()
{
  struct BstNode* root = NULL;
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  root = Insert(root,8);
  root = Insert(root,12);

  if(search(root,12))
   printf("element is found");
  else
   printf("element is not present");

  return 0;


}
