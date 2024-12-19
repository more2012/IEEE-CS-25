#include <bits/stdc++.h>
using namespace std;

set<string> result; 

void generatePermutations(string &s, int index) {
    if (index == s.size()) {
        result.insert(s);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);       
        generatePermutations(s, index + 1); 
        swap(s[index], s[i]);          
    }
}

int main() {
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    generatePermutations(input, 0);

  cout << result.size() << endl;
    for (const string &perm : result) {
        cout << perm << endl;
    }

    return 0;
}
