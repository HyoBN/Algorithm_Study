#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int start = v[0].first;
    int end = v[0].second;
    for (int i = 1; i < n; i++) {
        int s = v[i].first;
        int e = v[i].second;
        if (s <= end) {
            end = max(e, end);
        } else {
            ans += end - start;
            start = s;
            end = e;
        }
    }
    ans += end - start;
    cout << ans << "\n";
}
