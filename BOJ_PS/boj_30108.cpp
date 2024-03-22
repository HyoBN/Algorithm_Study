#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<long long> pq;
    long long n;
    long long ans=0;
    cin>>n;
    for (int i = 0; i < n - 1; i++) {
        long long tmp;
        cin>>tmp;
    }
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin>>tmp;
        pq.push(tmp);
    }

    while (!pq.empty()) {

        ans+= pq.top();
        pq.pop();
        cout << ans << '\n';
    }
}
