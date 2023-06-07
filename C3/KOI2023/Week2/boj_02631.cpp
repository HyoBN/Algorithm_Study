#include <iostream>
using namespace std;

int main(){
    int n,ans=1;
    int arr[201],dp[201];
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i]=1;
        for (int j = 0; j < i; j++) {
            if (arr[i]>arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout<<n-ans;
}
