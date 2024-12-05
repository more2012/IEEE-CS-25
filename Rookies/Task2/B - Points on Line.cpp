#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long d;
    cin >> n >> d;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && x[j] - x[i] <= d) {
            j++;
        }

        long long cnt = j - i - 1;

        if (cnt >= 2) {
            count += (cnt * (cnt - 1)) / 2; 
        }
    }

    cout << count << endl;

    return 0;
}
