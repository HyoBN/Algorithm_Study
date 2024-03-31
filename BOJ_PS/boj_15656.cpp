#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[8];
int output[8];

void backTracking(int cnt){
    if(cnt==m){
        for (int i = 0; i < m; i++) {
            cout<<output[i]<<' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        output[cnt] = arr[i];
        backTracking(cnt + 1);
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
