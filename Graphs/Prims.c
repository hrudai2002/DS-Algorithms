#include <stdio.h>
#include <stdbool.h>
#define INF 9999
#define MAX 100
int adj[MAX][MAX];
void prims(int n) {
    int src = 0;
   
    int selected[n];
    memset(selected, false, sizeof(selected));
    int no_edges = 0;
    selected[src] = true;
    int min_sum = 0;
    while(no_edges < n - 1) {
         int x = 0, y = 0;
         int min = INF;
        for(int i = 0; i < n; ++i) {
            if(selected[i]) {
                for(int j = 0; j < n; ++j) {
                    if(!selected[j] && adj[i][j]) {
                        if(min > adj[i][j]){
                            min = adj[i][j];
                            x = i, y = j;
                        }
                    }
                }
            }
        }
        selected[y] = true;
        min_sum += adj[x][y];
        no_edges += 1;
        
    }
    printf("%d", min_sum);
    
}
int main() {
    int v, e;
     scanf("%d %d", &v, &e);
    
    while(e--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v]  = w;
        adj[v][u] = w;
    }
    
    prims(v);
    
}
