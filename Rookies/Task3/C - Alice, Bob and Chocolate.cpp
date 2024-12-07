#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    int left = 0, right = n - 1;
    int time_alice = 0, time_bob = 0;
    int alice_bars = 0, bob_bars = 0;
    
    while (left <= right) {
        if (time_alice <= time_bob) {
            time_alice += t[left];
            alice_bars++;
            left++;
        } else {
            time_bob += t[right];
            bob_bars++;
            right--;
        }
    }
    
    cout << alice_bars << " " << bob_bars << endl;
    return 0;
}
