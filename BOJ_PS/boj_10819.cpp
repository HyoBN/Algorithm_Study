#include <iostream>

using namespace std;


int n,ans;
int arr[9];
int output[9];
bool visited[9];

void backTracking(int cnt, int summ){
    if(cnt==n){
        ans = max(ans, summ);
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i]=true;
            output[cnt] = arr[i];
            int calc=0;
            if(cnt>0) calc = abs(output[cnt] - output[cnt - 1]);
            backTracking(cnt + 1, summ + calc);
            visited[i]=false;
        }
    }
}
int main(){

    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    backTracking(0,0);
    cout<<ans;
}
