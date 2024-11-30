#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int luckyNumbers[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    for (int lucky : luckyNumbers) {
        if (n % lucky == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
