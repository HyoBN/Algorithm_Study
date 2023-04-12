#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ind[1001];
bool visited[1001];
vector<int> v[1001];
vector<int> ans;
queue<int> q;
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int singerCnt,preSingerNum;
        cin >> singerCnt;
        for (int j = 0; j < singerCnt; j++) {
            int singerNum;
            cin>>singerNum;
            if (j > 0) {
                v[preSingerNum].push_back(singerNum);
                ind[singerNum]++;
            }
            preSingerNum=singerNum;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            visited[i]=true;
            ans.push_back(i);
        }
    }
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < v[top].size(); i++) {
            int tmp = v[top][i];
            if (visited[tmp]) {
                cout<<0;
                return 0;
            }
            ind[tmp]--;
            if (ind[tmp] == 0) {
                q.push(tmp);
                visited[tmp]=true;
                ans.push_back(tmp);
            }
        }
    }
    if(ans.size()!=n) cout<<0;
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    }
}
