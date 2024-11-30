#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; 

    string directions;
    cin >> directions; 

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    int minTime = INT_MAX; 


    for (int i = 0; i < n - 1; i++) {
        if (directions[i] == 'R' && directions[i + 1] == 'L') {
            int distance = positions[i + 1] - positions[i];
            int collisionTime = distance / 2;
            minTime = min(minTime, collisionTime);
        }
    }

    if (minTime == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minTime << endl;
    }

    return 0;
}
