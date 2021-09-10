#include <stdio.h>
#include <stdlib.h>

struct BstNode{

  int data;
  struct BstNode* left;
  struct BstNode* right;
};

/* Creating a node in Binary Search Tree */
struct BstNode* GetnewNode(int data){
  struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
  newNode->data = data;
  newNode->right = newNode->left = NULL;

  return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
/* Inserting a node in a Binary Search Tree */
struct BstNode* Insert(struct BstNode* root,int data){
  
  if(root == NULL){
  root = GetnewNode(data);
  }

  else if(data <= root->data){
    root->left = Insert(root->left,data);
  }
  else{
    root->right = Insert(root->right,data);
  }

  return root;
}
/* Searching for a node in a Binary Search Tree */
int search(struct BstNode* root, int  data){

  if(root == NULL){
    return 0;
  }
  else if(root->data == data){
    return 1;
  }
  else if(data <= root->data){
    root = root->left;
  }
  else{
    root = root->right;
  }
}

/* Height of the Tree */
int height(struct BstNode* root) {
     if(root == NULL) {
		 return 0;
	 } 
	 int left  = height(root->left);
	 int right = height(root->right);

	 return max(left, right) + 1;

	
}


struct BstNode* findMin(struct BstNode* root){
     
     while(root->left != NULL) root = root->left;
     return root;
}

/* Deleting a Node in the binary search tree */
struct BstNode* Delete(struct BstNode* root,int data){
  if(root == NULL) return root;
  else if(data < root->data) root->left = Delete(root->left,data);
  else if(root->data < data) root->right = Delete(root->right,data);
  else{
    
    if(root->right == NULL && root->left == NULL){
         //free(root);
         root = NULL;
    }
    else if(root->right == NULL){
      struct BstNode* temp = root;
      root = root->left;
      free(temp);
    }
    else if(root->left == NULL){
      struct BstNode* temp = root;
      root = root->right;
      free(temp);
    }

    else{
      struct BstNode* temp = findMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right,temp->data);
    }

  }
  return root;

}
void Inorder(struct BstNode* root){
  if(root == NULL){
    return;
  }
  Inorder(root->left);
  printf("%d ",root->data);
  Inorder(root->right);
}

int main(){

  struct BstNode* root = NULL;
  root =  Insert(root,10);
  root =  Insert(root,8);
  root =  Insert(root,20);
  root =  Insert(root,4);
  root =  Insert(root,9);
  root =  Insert(root,11);
  root =  Insert(root,27);
  root =  Insert(root,23);
  root =  Insert(root,35);
  Inorder(root);
  printf("\n");
  root = Delete(root,11);
  Inorder(root);

  return 0;
}
