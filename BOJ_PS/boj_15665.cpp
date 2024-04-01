#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[8];
int output[8];
bool visited[8];

void backTracking(int cnt){
    if(cnt==m){
        for (int i = 0; i < m; i++) {
            cout<<output[i]<<' ';
        }
        cout << '\n';
        return;
    }
    int chk=0;
    for (int i = 0; i < n; i++) {
        if(arr[i]!=chk) {
            output[cnt] = arr[i];
            chk = output[cnt];
            backTracking(cnt + 1);
        }

    }

}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    backTracking(0);
}
