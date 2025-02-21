#include<iostream>
#include<algorithm>
using namespace std;

int n;
int input[1001][3];
int dp[1001][3];
int ans = 2147000000;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> input[i][0] >> input[i][1] >> input[i][2];

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (j == i) dp[1][j] = input[1][j];
            else dp[1][j] = 2147000000;
        }

        for (int j = 2; j <= n; j++)
        {
            dp[j][0] = input[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = input[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = input[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }

        for (int j = 0; j <= 2; j++)
        {
            if (j == i) continue;
            else ans = min(ans, dp[n][j]);
        }
    }
    cout << ans;
}
