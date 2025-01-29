#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj; // Adjacency list
vector<bool> visited;
int maxCost = 0;

void dfs(int node, int currentCost) {
    visited[node] = true;
    maxCost = max(maxCost, currentCost);
    
    for (auto& neighbor : adj[node]) {
        int nextNode = neighbor.first;
        int cost = neighbor.second;
        if (!visited[nextNode]) {
            dfs(nextNode, currentCost + cost);
        }
    }
    
    visited[node] = false; // Backtrack
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n);
    visited.resize(n, false);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    
    dfs(0, 0);
    
    cout << maxCost << endl;
    
    return 0;
}
