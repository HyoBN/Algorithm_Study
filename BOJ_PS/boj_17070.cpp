#include <iostream>
using namespace std;

int arr[21][21];
int n;


void dfs(int x, int y, int dir){
    arr[x][y]++;
    if (dir == 0 || dir == 2) {
        if(y<n && arr[x][y+1]!=1){
            dfs(x,y+1,0);
        }
    }
    if (dir == 1 || dir == 2) {
        if (x < n && arr[x + 1][y] != -1) {
            dfs(x + 1, y, 1);
        }
    }
    if(x<n && y<n && arr[x][y+1]!=-1 && arr[x+1][y]!=-1 && arr[x+1][y+1]!=-1)
        dfs(x + 1, y + 1, 2);
    return;
}

int main(){
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin>>arr[i][j];
            if(arr[i][j]==1) arr[i][j]=-1;
        }
    }
    dfs(1, 2, 0);

    if(arr[n][n]==-1)
        cout<<0;
    else cout << arr[n][n];
}
