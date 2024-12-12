#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(string start, string end) {
    int x1 = start[0] - 'a';
    int y1 = start[1] - '1';
    int x2 = end[0] - 'a';
    int y2 = end[1] - '1';

    queue<pair<int, int>> q;
    q.push({x1, y1});

    int moves = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == x2 && y == y2) return moves;

            for (int j = 0; j < 8; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    q.push({nx, ny});
                }
            }
        }
        moves++;
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string start, end;
        cin >> start >> end;

        cout << bfs(start, end) << endl;
    }

    return 0;
}
