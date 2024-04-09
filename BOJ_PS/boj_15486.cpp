#include <iostream>
using namespace std;

int dp[1500001];
int n, day, cost;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> day >> cost;
        dp[i + day] = max(dp[i + day], dp[i] + cost);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }
    cout << dp[n + 1];
}
