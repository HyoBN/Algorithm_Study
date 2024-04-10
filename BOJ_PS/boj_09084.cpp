#include <iostream>
#include <cstring>
using namespace std;

int dp[10001];
int coin[21];

int main() {
    int t,n,m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> coin[j];
        }

        cin >> m;

        for (int j = 0; j < n; j++) {
            for (int k = coin[j]; k <= m; k++) {
                dp[k] = dp[k] + dp[k - coin[j]];
            }
        }
        cout << dp[m] << "\n";
    }
}
