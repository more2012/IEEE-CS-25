#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    vector<int> cities(n), towers(m);

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    int min_r = 0;

    for (int i = 0; i < n; i++) {
        int city = cities[i];
        auto it = lower_bound(towers.begin(), towers.end(), city);

        int dist = INT_MAX;

        if (it != towers.end()) {
            dist = min(dist, abs(*it - city));
        }

        if (it != towers.begin()) {
            dist = min(dist, abs(*(it - 1) - city));
        }

        min_r = max(min_r, dist);
    }

    cout << min_r << endl;

    return 0;
}
