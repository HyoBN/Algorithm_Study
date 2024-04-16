#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[10001];
int main(){
    priority_queue<pair<int,int>> pq;
    int n,d,p,ans=0;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>p>>d;
        pq.push({p, d});
    }
    while (!pq.empty()) {
        pair<int, int> tmp = pq.top();
        pq.pop();
        for (int i = tmp.second; i >= 1; i--) {
            if (!visited[i]) {
                visited[i]=true;
                ans+=tmp.first;
                break;
            }
        }
    }
    cout<<ans;
}
