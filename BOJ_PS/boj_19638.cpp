#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,h,t;
    int cnt=0;
    priority_queue<int> giants;
    cin>>n>>h>>t;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        giants.push(tmp);
    }
    while (t--) {
        int giant = giants.top();
        if(giant==1 || giant<h){
            break;
        }
        giants.pop();
        giants.push(giant / 2);
        cnt++;
    }

    if(giants.top()<h){
        cout<<"YES\n"<<cnt;
    }
    else cout << "NO\n" << giants.top();
}
