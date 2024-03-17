#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    long long t, k;
    long long tmpFile;
    cin >> t;

    while (t--) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0;
        cin >> k;
        while (k--) {
            cin >> tmpFile;
            pq.push(tmpFile);
        }
        while (!pq.empty()) {
            if (pq.size() <= 1)
                break;
            long long sumFile = 0;

            for(int i=0;i<2;i++){
                sumFile += pq.top();
                pq.pop();
            }
            ans += sumFile;
            pq.push(sumFile);
        }
        cout<<ans<<'\n';
    }
}
