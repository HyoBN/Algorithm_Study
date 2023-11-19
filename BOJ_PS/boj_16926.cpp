#include <iostream>
#include <algorithm>
using namespace std;

int arr[301][301];
int n,m,r;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void rotate(int box){
    for (int i = 0; i < box; i++) {
        int start = arr[i][i];
        int y=i;
        int x=i;

        int k=0;
        while (k < 4) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if(ny == i && nx == i) break;
            if (ny >= i && ny < n - i && nx >= i && nx < m - i) {
                arr[y][x] = arr[ny][nx];
                y=ny, x=nx;
            }else{
                k++;
            }
        }
        arr[i+1][i]=start;
    }
}
int main(){
    cin>>n>>m>>r;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        rotate(min(n, m) / 2);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<arr[i][j]<<' ';
        }
        cout << '\n';
    }

}
