#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
int num[10001];

void dfs(int start, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    } else{
        for(int i=start;i<=n;i++){
            arr[cnt]=num[i];
            dfs(i+1,cnt+1);
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        cin>>num[i];
    }
    sort(num+1, num + n+1);
    dfs(1, 0);
}
