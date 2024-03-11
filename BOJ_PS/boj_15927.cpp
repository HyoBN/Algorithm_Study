#include <iostream>
using namespace std;

int main(){
    string s;
    char firstChar;
    bool sameFlag = true;

    cin >> s;
    firstChar = s[0];

    for (int i = 0; i <= s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            cout << s.length();
            return 0;
        }
        if (s[i] != firstChar) {
            sameFlag=false;
        }

    }
    if (sameFlag) {
        cout << -1;
    } else cout << s.length() - 1;

}
