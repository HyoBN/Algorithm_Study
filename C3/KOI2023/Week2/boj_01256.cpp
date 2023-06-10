#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    long long dp[101][101];
    cin>>n>>m>>k;

    for (int i = 1; i <= 100; i++) {
        dp[i][0]=1,dp[0][i]=1;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
        }
    }

    int aCnt=n;
    int zCnt=m;
    if (dp[n][m] < k) {
        cout<<-1;
        return 0;
    }

    for (int i = 0; i < n + m; i++) {
        int aStart = dp[aCnt - 1][zCnt];
        if (aCnt == 0) {
            cout << 'z';
            zCnt--;
            continue;
        } else if (zCnt == 0) {
            cout << 'a';
            aCnt--;
            continue;
        }
        if (k <= aStart) {
            cout << 'a';
            aCnt--;
        }else{
            k-=aStart;
            cout << 'z';
            zCnt--;
        }
    }
}
