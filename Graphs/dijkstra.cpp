#include <bits/stdc++.h>
using namespace std;
#define INF 100001

void dijkstra(vector<pair<int, int>> adj[], int n) {
    int src = 0;
    
    vector<int> dis(n, INF);
    dis[src] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, src}); 

    while(!pq.empty()) {
        int u = pq.top().second; 
        pq.pop();
        
        for(auto x : adj[u]) {
            int v = x.first, w = x.second;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << dis[i] << " ";
    }
}

int main() {
    int vertices, edges; 
    cin >> vertices >> edges; 

    vector<pair<int, int>> adj[vertices]; 

    for(int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w; 
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(adj, vertices);
}