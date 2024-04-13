#include <iostream>
#include <cmath>
using namespace std;

int dp[10001];
int n, k, coin[101];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        dp[i] = 10001;
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> coin[i];
        
        for (int j = coin[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);        
        }                                                  
    }

    if (dp[k] == 10001) dp[k]=-1;
    cout << dp[k];
}
