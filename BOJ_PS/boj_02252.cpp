#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int> v[32001];
    queue<int> q;
    int ind[32001];

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        ind[y]++;
    }

    for(int i=1;i<=n;i++){
        if(ind[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        for (int i = 0; i < v[top].size(); i++) {
            ind[v[top][i]]--;
            if (ind[v[top][i]] == 0) {
                q.push(v[top][i]);
            }
        }
    }

}
