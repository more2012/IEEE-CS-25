#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> hasCat;         
vector<vector<int>> adj;     
int result = 0;

void dfs(int node, int parent, int catCount) {
    if (hasCat[node]) {
        catCount++; 
    } else {
        catCount = 0;  
    }

    if (catCount > m) return;

    bool isLeaf = true; 
    for (int neighbor : adj[node]) {
        if (neighbor != parent) { 
            isLeaf = false;  
            dfs(neighbor, node, catCount);
        }
    }

    if (isLeaf) result++;
}

int main() {
    cin >> n >> m;
    
    hasCat.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> hasCat[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0); 
    cout << result << "\n";

    return 0;
}
