#include <iostream>
using namespace std;

int n,k;
int kit[10];
bool visited[10];
int ans=0;

void backTracking(int cnt, int weight){
    if(cnt==n){
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i]=true;
            int nowWeight=weight + kit[i]-k;
            if (nowWeight < 500) {
                visited[i]=false;
                continue;
            }
            backTracking(cnt + 1, nowWeight);

            visited[i]=false;
        }
    }
}

int main(){
    cin>>n>>k;
    for (int i = 0; i < n; i++) {
        cin >> kit[i];
    }
    backTracking(0, 500);
    cout<<ans;
}
