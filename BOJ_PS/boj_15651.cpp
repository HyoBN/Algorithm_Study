#include <iostream>
using namespace std;

int n,m;
int arr[10];
void dfs(int start, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    } else{
        for(int i=1;i<=n;i++){
            arr[cnt]=i;
            dfs(i,cnt+1);
        }
    }
}
int main(){
    cin>>n>>m;
    dfs(1, 0);
}
