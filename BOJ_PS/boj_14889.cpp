
#include <iostream>
#include <cmath>
using namespace std;

int arr[21][21];
bool visited[21];
int n;
int ans =2147000000;

void dfs(int cnt, int pos){
    if(cnt==n/2){
        int start=0, link=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i] && visited[j]) start +=arr[i][j];
                if(!visited[i] && !visited[j]) link +=arr[i][j];
            }
        }
        ans = min(ans,abs(start-link));
        return;
    }
    
    for(int i=pos;i<n;i++){
        visited[i]=true;
        dfs(cnt+1,i+1);
        visited[i]=false;
    }
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    dfs(0,0);
    cout<<ans;
}
