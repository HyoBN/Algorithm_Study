#include <iostream>
using namespace std;

int n,ans=1;
int box[1001];
int dp[1001];
int main(){
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> box[i];
        dp[i]=1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (box[i] > box[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout<<ans;
}
