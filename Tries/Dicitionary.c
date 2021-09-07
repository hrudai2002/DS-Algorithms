#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct Trie {
  int flag;
  struct Trie *child[257];
};

struct Trie* getnode() {
  struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));
  node->flag = 0;

  for(int i = 0; i < 257; ++i) {
    node->child[i] = NULL;
  }
  return node;
}

void Insert(struct Trie *root, char *s) {
   struct Trie *temp = root;
   for(int i = 0; i < strlen(s); ++i) {
            if(temp->child[s[i]] == NULL){
               temp->child[s[i]] = getnode();
           }
           temp = temp->child[s[i]];
   }
   temp->flag = 1;
}

void Search(struct Trie *root, char *s) {
  struct Trie *temp = root;
  for(int i = 0; i < strlen(s); ++i) {
      if(temp->child[s[i]] == NULL) {
         break;
      }
      else {
         temp = temp->child[s[i]];
      }
  }
  if(temp->flag) {
    printf("Element present in the dictionary \n");
  }
  else {
    printf("Element is not present in the dictionary \n");
  }
}
int main() {
   int t;
   scanf("%d", &t);
   struct Trie *root = getnode();
   /*
    3
    India
    NewYork
    England

   */
   while(t--) {
     char s[MAX];
     scanf("%s", s);
     Insert(root, s);
   }
  int q;
  scanf("%d", &q);
  /*
  4
  Hongkong
  England
  China
  India

  */
  while(q--) {
     char s[MAX];
     scanf("%s", s);
     Search(root, s);
  }

}
