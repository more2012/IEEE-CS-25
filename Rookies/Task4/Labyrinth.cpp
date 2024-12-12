#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'A') {
                sx = i;
                sy = j;
            } else if (map[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }

    queue<pair<pair<int, int>, string>> q;
    q.push({{sx, sy}, ""});

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        string path = q.front().second;
        q.pop();

        if (x == ex && y == ey) {
            cout << "YES" << endl;
            cout << path.length() << endl;
            cout << path << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#' && !visited[nx][ny]) {
                q.push({{nx, ny}, path + dir[i]});
                visited[nx][ny] = true;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
