#include <iostream>
using namespace std;

int n;
int output[10];
bool visited[10];

void backTracking(int cnt){
    if(cnt==n){
        for (int i = 0; i < n; i++) {
            cout<<output[i]<<' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        if(!visited[i]){
            visited[i]=true;
            output[cnt]=i;
            backTracking(cnt + 1);
            visited[i]= false;
        }
    }



}
int main(){
    cin>>n;

    backTracking(0);
}
