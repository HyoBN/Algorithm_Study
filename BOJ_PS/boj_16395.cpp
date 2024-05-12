#include <iostream>
using namespace std;
int dp[31][31];

int main() {

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 31; i++)
        dp[i][0] = 1;

    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n - 1][k - 1];
}
