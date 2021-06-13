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
        if(flag == 0) rear = -1, flag = 1;
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
  
   /* 
      input:
      5 
      0 1 1 1 0
      1 0 1 0 1
      1 1 0 0 1
      1 0 0 0 1
      0 1 1 1 0
      
      output:
      1 2 3 4 5
   
   */

    scanf("%d",&n);  // No of vertices
    for(int i = 1; i <= n; ++i) {  // Adjacency Matrix
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }
    BFS(); // BFS traversal
    return 0;
}
