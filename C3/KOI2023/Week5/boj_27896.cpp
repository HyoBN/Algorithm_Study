#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main(){
    int n,m;
    int angry=0,ans=0;
    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        pq.push(tmp);
        angry+=tmp;
        while (angry >= m) {
            angry -= 2 * pq.top();
            pq.pop();
            ans++;
        }
    }
    cout<<ans;
}
