#include <iostream>
using namespace std;


int arr[1001];
int dp[1001];
int main() {
    int n,ans=0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(arr[i] < arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
