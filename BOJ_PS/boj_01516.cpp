#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ind[501];
int buildTime[501];
int sum[501];
vector<int> v[501];

int main(){
    int n;
    queue<int> q;
    cin>>n;

    for (int i = 1; i <= n; i++) {
        int t,tmp;
        cin >> t;
        buildTime[i]=t;
        cin>>tmp;
        while (tmp!=-1) {
            v[tmp].push_back(i);
            cin>>tmp;
            ind[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if(ind[i]==0) {
            q.push(i);
            sum[i] = buildTime[i];
        }
    }

    for (int k = 0; k < n; k++) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < v[top].size(); i++) {
            int tmp = v[top][i];
            ind[tmp]--;
            sum[tmp] = max(sum[tmp], sum[top] + buildTime[tmp]);
            if (ind[tmp] == 0) {
                q.push(tmp);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << sum[i] << "\n";
}
