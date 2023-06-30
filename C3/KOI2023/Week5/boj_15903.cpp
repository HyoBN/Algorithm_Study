#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    long long n,m,ans=0;
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    for (int i = 0; i < m; i++) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    while (!pq.empty()) {
        long long tmp = pq.top();
        pq.pop();
        ans+=tmp;
    }
    cout<<ans;
}
