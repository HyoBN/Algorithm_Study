#include <iostream>
#include <vector>
using namespace std;

long long dp[10001];
vector<pair<int,int>> v;
int main(){
    int n,t;
    cin>>n>>t;

    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
        for (int j = t; j >= v[i].first; j--) {
            dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
        }
    }
    cout << dp[t];

}
