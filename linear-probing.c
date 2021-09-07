#include <stdio.h>
int hash[1001];
int n;
void print() {
	for(int i = 0; i < n; ++i) {
		printf("%d ", hash[i]);
	}
	printf("\n");
}

void Insert(int x) {
	int index = x % n;
	int i = 1;
	while(hash[index] != -1) {
        index = (x + i) % n;
		i += 1;
	}
    hash[index] = x;
}

void Delete(int x) {
	int dup[n];
	for(int i = 0; i < n; ++i) {
		dup[i] = hash[i];
		if(dup[i] == x) {
			dup[i] = -1;
		}
		hash[i] = -1;
	}
	for(int i = 0; i < n; ++i) {
		Insert(dup[i]);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	    hash[i] = -1;
	
	int t;
	scanf("%d", &t);
	while(t--) {
          int x;
		  scanf("%d", &x);
		  if(x == 1) {
             int num;
			 scanf("%d", &num);
			 Insert(num);
		  }
		  else if(x == 2) {
             int num;
			 scanf("%d", &num);
			 Delete(num);

		  }
		  else if(x == 3) {
             print(hash);
		  }
		  
	}
}
