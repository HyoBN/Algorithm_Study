#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool flag;
vector<int> v[2001];
bool visited[2001];

void dfs(int nowIdx, int cnt){
    if(flag) return;
    if(cnt==5){
        flag=true;
        return;
    }
    if(!visited[nowIdx]){
        visited[nowIdx]=true;
        for (int i = 0; i < v[nowIdx].size(); i++) {
            if(!visited[v[nowIdx][i]]){
                dfs(v[nowIdx][i], cnt + 1);
            }
        }
        visited[nowIdx]=false;
    }
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(i,1);
    }
    cout << (flag ? 1 : 0);
}
