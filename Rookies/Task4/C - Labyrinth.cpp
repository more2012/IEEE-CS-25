#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> labyrinth(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    int startX, startY, endX, endY;

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (labyrinth[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == endX && y == endY) {
            cout << "YES" << endl;

            // Reconstruct the path
            string path = "";
            while (x != startX || y != startY) {
                auto [px, py] = parent[x][y];
                for (int i = 0; i < 4; i++) {
                    if (px + dx[i] == x && py + dy[i] == y) {
                        path += dir[i];
                        break;
                    }
                }
                x = px;
                y = py;
            }

            reverse(path.begin(), path.end());
            cout << path.length() << endl;
            cout << path << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && labyrinth[newX][newY] != '#') {
                visited[newX][newY] = true;
                parent[newX][newY] = {x, y};
                q.push({newX, newY});
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
