#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[101];
vector<int> ans;
queue<int> q;
int ind[101];
int sum[101];

int main(){
    int n,m;
    cin>>n>>m;
    while (m--) {
        int x,y,k;
        cin>>x>>y>>k;
        v[x].push_back({y, k});
        ind[y]++;
    }
    q.push(n);
    sum[n] = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (v[top].empty()) {
            ans.push_back(top);
        }
        for (int i = 0; i < v[top].size(); i++) {
            int next=v[top][i].first;
            sum[next] += sum[top] * v[top][i].second;
            ind[next]--;
            if(ind[next]==0) q.push(next);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<' '<<sum[ans[i]]<<'\n';
    }
}
