#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> representatives;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            representatives.push_back(i);  
            bfs(i, graph, visited);      
        }
    }
    int requiredRoads = representatives.size() - 1;
    cout << requiredRoads << endl;
    for (int i = 1; i < representatives.size(); i++) {
        cout << representatives[i - 1] << " " << representatives[i] << endl;
    }

    return 0;
}
