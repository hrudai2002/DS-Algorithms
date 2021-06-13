/*   
Implementation of BFS using adjacency Matrix 
Time Complexity O(n*e) 
n - number of vertices
e - number of edges
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 
int adj[SIZE][SIZE];
int q[SIZE];
int n, front, rear;

void BFS() {
    int visited[n + 1]; // keeping track of visited elements
    for(int i = 1; i <= n; ++i) visited[i] = 0;
    int src = 1;
    visited[src] = 1;
    int flag = 0;
    printf("%d ",src);
    
     while(front <= rear) {
        if(flag == 0) rear = -1, flag = 1; // keeping rear = -1 so that rear starts iterating from 0
        for(int i = 1; i <= n; ++i) {
            if(adj[src][i] == 1 && visited[i] == 0) {
                rear += 1;
                q[rear] = i;
                visited[i] = 1;
            }
      }
        src = q[front];
        printf("%d ",q[front]);
        front++;
     }
}

int main() {
  int e;
     scanf("%d", &e);
    /* Input 1: 
       when nodes are input
        eg: 13 10 [no of vertices : 13, no of edges : 10]
            1 2  // following are the edges between the nodes
            1 3
            1 4
            2 7
            2 8
            2 9
            3 10
            3 11
            4 12
            4 13  */
    while(e--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // Input 2 : Matrix
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d",&adj[i][j]);
        }
    }
      BFS(); // BFS traversal
      return 0;
}
