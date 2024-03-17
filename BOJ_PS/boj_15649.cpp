#include <iostream>
using namespace std;

int n,m;
int arr[10];
bool visited[10];

void dfs(int cnt){
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout<<arr[i]<<' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i]=true;
            arr[cnt]=i;
            dfs(cnt + 1);
            visited[i]=false;
        }
    }
}

int main(){
    cin>>n>>m;
    dfs(0);
}
