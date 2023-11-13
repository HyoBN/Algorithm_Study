#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
bool visited[10];
vector<int> v;
void dfs(int cnt){
    if(cnt>m) {
        for (int i = 0; i < v.size(); i++) {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if(visited[i]) continue;
        visited[i]=true;
        v.push_back(arr[i]);
        dfs(cnt + 1);
        v.pop_back();
        visited[i]=false;
    }
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(1);
}
