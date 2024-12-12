#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.') {
                queue<pair<int, int>> q;
                q.push({i, j});

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if (map[x][y] == '.') {
                        map[x][y] = '#';

                        if (x > 0) q.push({x - 1, y});
                        if (x < n - 1) q.push({x + 1, y});
                        if (y > 0) q.push({x, y - 1});
                        if (y < m - 1) q.push({x, y + 1});
                    }
                }

                rooms++;
            }
        }
    }

    cout << rooms << endl;

    return 0;
}
