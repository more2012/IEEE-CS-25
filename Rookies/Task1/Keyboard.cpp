#include <iostream>
#include <string>
using namespace std;

int main() {
    char direction;
    string typedMessage;
    cin >> direction;  
    cin >> typedMessage;  

    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl;";
    string row3 = "zxcvbnm,./";

    string originalMessage = "";

    for (int i = 0; i < typedMessage.length(); i++) {
        char c = typedMessage[i]; 

        if (row1.find(c) != string::npos) {
            int idx = row1.find(c);
            if (direction == 'R') {
                originalMessage += row1[idx - 1];  
            } else {
                originalMessage += row1[idx + 1];  
            
        } else if (row2.find(c) != string::npos) {
            int idx = row2.find(c);
            if (direction == 'R') {
                originalMessage += row2[idx - 1]; 
            } else {
                originalMessage += row2[idx + 1];
            }
        } else if (row3.find(c) != string::npos) {
            int idx = row3.find(c);
            if (direction == 'R') {
                originalMessage += row3[idx - 1]; 
            } else {
                originalMessage += row3[idx + 1];
            }
        }
    }

    cout << originalMessage << endl;

    return 0;
}
