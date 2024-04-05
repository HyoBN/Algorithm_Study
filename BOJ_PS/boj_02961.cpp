#include <iostream>
#include <cmath>
using namespace std;

long long n,ans=2147000000;
long long sour[12];
long long bitter[12];
bool visited[12];

void backTracking(long long cnt, long long sourSum, long long bitterSum){
    if(cnt>n){
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i]= true;
            ans = min(ans, abs(sourSum * sour[i] - (bitterSum + bitter[i])));
            backTracking(cnt + 1, sourSum * sour[i], bitterSum + bitter[i]);
            visited[i]= false;
        }
    }
}

int main(){
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> sour[i] >> bitter[i];
    }
    backTracking(0,1,0);
    cout<<ans;
}
