#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    Point start, end;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Point>> parent(n, vector<Point>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));

    int dx[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y) break;

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = curr;
                direction[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }

    if (!visited[end.x][end.y]) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    string path;
    Point curr = end;
    while (curr.x != start.x || curr.y != start.y) {
        char d = direction[curr.x][curr.y];
        path += d;
        int idx = -1;
        for (int i = 0; i < 4; i++) {
            if (dir[i] == d) {
                idx = i;
                break;
            }
        }
        curr = parent[curr.x - dx[idx]][curr.y - dy[idx]];
    }

    reverse(path.begin(), path.end());
    cout << path.length() << '\n';
    cout << path << '\n';

    return 0;
}
