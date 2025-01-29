#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        int maxVol = 0;
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int currentVol = 0;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    currentVol += grid[i][j];
                    grid[i][j] = 0;  // ✅ تصحيح الخطأ هنا

                    while (!st.empty()) {
                        auto [x, y] = st.top();
                        st.pop();

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > 0) {
                                currentVol += grid[nx][ny];
                                grid[nx][ny] = 0;
                                st.push({nx, ny});
                            }
                        }
                    }
                    
                    maxVol = max(maxVol, currentVol);
                }
            }
        }
        
        cout << maxVol << '\n';
    }
    
    return 0;
}
