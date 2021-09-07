#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Trie {
	int flag;
	struct Trie *child[10];
};

struct Trie *getnode() {
	struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));
	node->flag = 0;

	for(int i = 0; i < 10; ++i) {
		node->child[i] = NULL;
	}
	
	return node;
}

void Insert(struct Trie *root, char *s) {
	struct Trie *temp = root;
	for(int i = 0; i < strlen(s); ++i) {
		 int id = s[i] - 48;
         if(temp->child[id] == NULL) {
			 temp->child[id] = getnode();
		 }
		 temp = temp->child[id];
	}
	if(temp->flag == 0) {
		printf("%s\n", s);
	}
	temp->flag = 1;
}
int main() {
	int t;
	scanf("%d", &t);
	struct Trie *root = getnode();
	while(t--) {
      char s[MAX];
	  scanf("%s", s);
	  Insert(root, s);
	}
}
