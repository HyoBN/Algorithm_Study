#include <iostream>
#include <cstring>
using namespace std;

int dp[16][16];

int main() {
	int n, m, k;
	int ans;
	cin >> n >> m >> k;
	dp[0][1] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

	if (k == 0) cout << dp[n][m];
	else {
		int y, x;
		if (k % m == 0) {
			y = k / m;
			x = m;
		}
		else {
			y = (k - k % m) / m + 1;
			x = k % m;
		}
		cout << dp[y][x] * dp[n - y + 1][m - x + 1];
	}
}
