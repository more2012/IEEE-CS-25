#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;  
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> seen;  
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i] - k) != seen.end()) {
            count++;
        }
        if (seen.find(arr[i] + k) != seen.end()) {
            count++;
        }
        seen.insert(arr[i]);
    }

    cout << count << endl;

    return 0;
}
