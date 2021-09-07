#include <stdio.h>
#include <stdlib.h>
int Graph[1001][1001];
int level[1001];
int visited[1001] = {0};
int N;
void BFS(int v) {
    int q[1001];
	int size = 0;
	q[size++] = v;
	level[v] = 0;
	int front = 0; 
	while(front < size) {
        int z = q[front];
		for(int i = 1; i <= N; ++i) {
			if(Graph[z][i] == 1 && visited[i] == 0) {
				level[i] = level[z] + 1;
				q[size++] = i;
			}
		}
		front++;
		if(visited[z] == 0){
			visited[z] = 1;
		}
	}
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		Graph[u][v] = 1;
		Graph[v][u] = 1;
	}
    BFS(1);
	int Q;
	scanf("%d", &Q);
	int mnh = 10001;
    int mnid = 10001;
	while(Q--) {
		int v;
		scanf("%d", &v);
		
		if(level[v] <= mnh) {
			if(level[v] == mnh) {
				if(v < mnid) {
					mnid = v;
				}
			}
			else {
				mnid = v;
				mnh = level[v];
			}
		}
	}
	printf("%d", mnid);

}
