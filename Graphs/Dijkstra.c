#include <stdio.h>
#define MAX 100
#define INF 9999
int adj[MAX][MAX];
void Dijkstra(int adj[MAX][MAX], int n, int src) {
    int cost[n + 1][n + 1], visited[n + 1], dis[n + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(adj[i][j] == 0) {
                cost[i][j] = INF;
            } else {
                cost[i][j] = adj[i][j];
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        dis[i] = cost[src][i];
        visited[i] = 0;
    }
    visited[src] = 1;
    dis[src] = 0;
    int count = 1, mindis, nextnode;
    while(count < n) {
        mindis = INF;
        for(int i = 1; i <= n; ++i) {
            if(dis[i] < mindis && !visited[i]) {
                mindis = dis[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for(int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                if(mindis + cost[nextnode][i] < dis[i]) {
                    dis[i] = mindis + cost[nextnode][i];
                }
            }
        }
        count++;
    }
    
    for(int i = 1; i <= n; ++i) {
        if(i != src) {
            printf("Distance from source to %d: %d\n", i, dis[i]);
        }
    }
}
int main() {
    /* 
    Input : 
    5 7    // no of vertices, no of edges
    1 2 3  // source node, destination node, weight 
    1 4 7
    2 3 2
    3 5 1
    5 4 4
    1 3 8
    1 5 6
    
    Output: 
    Distance from source 2 to 3
    Distance from source 3 to 5
    Distance from source 4 to 7
    Distance from source 5 to 6
 */
    int v, e;
     scanf("%d %d", &v, &e);
     while(e--) {
         int u, v, w;
         scanf("%d %d %d", &u, &v, &w);
         adj[u][v] = w;
         adj[v][u] = w;
     }
     
     Dijkstra(adj, v, 1);
}
