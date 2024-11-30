#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int max_height = heights[0], min_height = heights[0];
    int max_pos = 0, min_pos = 0;

    for (int i = 0; i < n; i++) {
        if (heights[i] > max_height) {
            max_height = heights[i];
            max_pos = i;
        }
        if (heights[i] <= min_height) {
            min_height = heights[i];
            min_pos = i;
        }
    }

    int moves = max_pos + (n - 1 - min_pos);

    if (max_pos > min_pos) {
        moves -= 1;
    }

    cout << moves << endl;
    return 0;
}
