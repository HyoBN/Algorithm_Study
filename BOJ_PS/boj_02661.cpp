#include <iostream>
#include <string>
using namespace std;

int n;
string ans;
bool finish;

void backTracking(string tmp, int cnt) {
    if (finish) return;
    int size = tmp.size();
    for (int i = 1; i <= size / 2; i++) {
        if (tmp.substr(size - i, i) == tmp.substr(size - (2 * i), i))
            return;
    }
    if (cnt == n) {
        ans = tmp;
        finish = true;
    }
    for (int i = 0; i < n; i++) {
        backTracking(tmp + "1", cnt + 1);
        backTracking(tmp + "2", cnt + 1);
        backTracking(tmp + "3", cnt + 1);
    }
}

int main() {
    cin >> n;
    backTracking("", 0);
    cout << ans;
}
