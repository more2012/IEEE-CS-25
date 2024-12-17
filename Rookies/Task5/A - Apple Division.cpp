#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> weights; 
int n; 

int solve(int i, int group1, int group2) {
    if (i == n) {
        return abs(group1 - group2); 
    }

    int option1 = solve(i + 1, group1 + weights[i], group2);

    int option2 = solve(i + 1, group1, group2 + weights[i]);

    return min(option1, option2);
}

int32_t main() {
    cin >> n;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << solve(0, 0, 0) << endl;

    return 0;
}
