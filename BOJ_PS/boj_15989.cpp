#include <iostream>
using namespace std;

int t, n;
int dp[10001]={1,};

int main() {
    cin >> t;

    for(int i = 1; i < 4; i++){
        for(int j = 1; j <= 10000; j++){
            if(j - i >= 0)
                dp[j] += dp[j - i];
        }
    }
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
}
