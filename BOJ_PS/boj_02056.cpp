#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,totalTime=0;
    queue<int> q;
    int ind[10001];
    int time[10001];
    int sum[10001];
    vector<int> v[10001];
    cin>>n;


    for (int i = 1; i <= n; i++) {
        int t,cnt;
        cin >> t;
        cin >> cnt;
        time[i]=t;
        ind[i]=cnt;
        while (cnt--) {
            int tmp;
            cin>>tmp;
            v[tmp].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if(ind[i]==0) {
            q.push(i);
            sum[i] = time[i];
        }
    }

    for (int k = 0; k < n; k++) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < v[top].size(); i++) {
            int tmp = v[top][i];
            ind[tmp]--;
            if (sum[tmp] < sum[top] + time[tmp]) {
                sum[tmp] = sum[top] + time[tmp];
            }
            if (ind[tmp] == 0) {
                q.push(tmp);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if(totalTime<sum[i])
            totalTime = sum[i];
    }
    cout << totalTime;
}
