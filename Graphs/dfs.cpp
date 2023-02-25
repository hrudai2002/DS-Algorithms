#include <bits/stdc++.h>
using namespace std; 


void dfs(vector<int> adj[], vector<bool> &vis, int src) {
   cout << src << " ";
   vis[src] = true;
   for(auto x : adj[src]) {
    if(!vis[x]) {
        dfs(adj, vis, x);
    }
   }
}

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 

    vector<int> graph[vertices];
    for(int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int src = 0;
    vector<bool> vis(vertices, false);
    dfs(graph, vis, src);
}