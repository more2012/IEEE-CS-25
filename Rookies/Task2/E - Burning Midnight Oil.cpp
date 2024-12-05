#include <iostream>
using namespace std;

long long calculateLines(long long v, int k) {
    long long sum = 0;
    long long current = v;
    while (current > 0) {
        sum += current;        
        current /= k;          
    }
    return sum;
}

int main() {
    long long n;  
    int k;        
    cin >> n >> k;

    long long left = 1, right = n, result = n;  
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (calculateLines(mid, k) >= n) {
            result = mid;  
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;  
    return 0;
}
