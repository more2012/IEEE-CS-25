#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100005]; 
bool visited[100005]; 

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    
    int tribes = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            tribes++; 
        }
    }
    
    cout << tribes << "\n";
    return 0;
}
