/* 
Implementation of DFS using Adjacency Matrix
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int n;
int adj[SIZE][SIZE];


void DFS(int src, int visited[]) {
   if(visited[src] == 0) {
       printf("%d ",src);
       visited[src] = 1;
   }
   
   for(int i = 1; i <= n; ++i) {
       if(adj[src][i] == 1 && visited[i] == 0) {
           DFS(i, visited);
       }
   }
}

int main() {

    scanf("%d",&n);
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
    
    int visited[n + 1];
    for(int i = 1; i <= n; ++i) visited[i] = 0;
    
    DFS(1, visited);
    // Without Recusrion
    int stack[SIZE];
    int top = -1;
    int src = 1;
    visited[src] = 1;
    for(int i = 1; i <= n; ++i) {
       if(adj[src][i]){
           stack[++top] = i;
       }
    }
    while(top > -1) {
       src = stack[top];
       printf("%d ", src);
       visited[src] = 1;
       top--;
       for(int i = 0; i <= n; ++i) {
         if(adj[src][i]) {
           stack[++top] = i;
         }
       }
    }
    return 0;
}
