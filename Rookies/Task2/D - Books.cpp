#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t; 
    int books[100000];
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int maxBooks = 0;
    int currentSum = 0;
    int left = 0; 

    for (int right = 0; right < n; right++) {
        currentSum += books[right]; 

        while (currentSum > t) { 
            currentSum -= books[left]; 
            left++; 
        }

        int currentBooks = right - left + 1; 
        if (currentBooks > maxBooks) {
            maxBooks = currentBooks; 
        }
    }

    cout << maxBooks << endl; 
    return 0;
}
