#include <stdio.h>
#define MAX 100
int Graph[MAX][MAX];
int n;
int q[MAX];
int front, rear;
void BFS() {
    int visited[n];
    memset(visited, 0, sizeof(visited));
    int src = 0;
    visited[src] = 1;
    int flag = 0;
    q[front] = src;
    while(front <= rear) {
        int curr = q[front];
        for(int i = 0; i < n; ++i) {
            if(!visited[i] && Graph[curr][i]) {
                rear += 1;
                q[rear] = i;
                visited[i] = 1;
            }
        }
        printf("%d ",curr);
        front++;
     }
}
int main() {
    int e;
    scanf("%d %d", &n, &e);
    while(e--) {
        int u, v;
        scanf("%d %d", &u, &v);
        Graph[u][v] = 1;
        Graph[v][u] = 1;
    }
    BFS();
}
