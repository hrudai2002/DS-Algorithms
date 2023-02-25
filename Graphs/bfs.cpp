#include <bits/stdc++.h>
using namespace std; 


void bfs(vector<int> adj[], int vertices) {
    int src = 0;
    queue<int> q; 
    vector<bool> vis(vertices, 0);
    q.push(src); 
    vis[src] = true;

    while(!q.empty()) {
        int node = q.front();
        cout << node << " "; 
        q.pop(); 

        for(auto x : adj[node]) {
            if(!vis[x]) {
                vis[x] = true;
                q.push(x);
            }
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

    bfs(graph, vertices);
}