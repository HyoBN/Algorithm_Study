#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;

int main() {
    int n, m, hour, ans = 0;
    int a[200000];
    cin >> n >> m;
    hour = n * 24;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        pq.push({b, 100-a[i]});
    }

    while (!pq.empty()) {
        if(hour==0) break;
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        if (x <= y) {
            ans += x;
            pq.push({x, y-x});
            hour--;
        }
        else 
            pq.push({y, y});
    }
    cout << ans;
}
