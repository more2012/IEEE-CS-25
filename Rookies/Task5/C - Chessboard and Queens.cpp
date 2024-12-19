#include <bits/stdc++.h>
using namespace std;

int countWays = 0; 
bool column[8];    
bool diag1[15];   
bool diag2[15];   
char board[8][8];

void solve(int row) {
    if (row == 8) {
        countWays++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*' || column[col] || diag1[row + col] || diag2[row - col + 7]) {
            continue; 
        }
        column[col] = diag1[row + col] = diag2[row - col + 7] = true;
        solve(row + 1);
        column[col] = diag1[row + col] = diag2[row - col + 7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    solve(0);
    cout << countWays << endl;

    return 0;
}
