#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());  
    int left = 0, max_students = 0;
    for (int right = 0; right < n; right++) {
        while (a[right] - a[left] > 5) {
            left++;
        }
        max_students = max(max_students, right - left + 1);
    }

    cout << max_students << endl;

    return 0;
}
