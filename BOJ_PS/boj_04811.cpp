#include <iostream>
using namespace std;

int main()
{
    int n;
    long long dp[31]={1,1,2,};

    for (int i = 3; i < 31; i++){
        for (int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    while (true)
    {
        cin >> n;
        if (n == 0) break;
        cout << dp[n] << '\n';
    }
}
