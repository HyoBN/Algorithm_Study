#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,ans=1;
    int dp[101];
    vector<pair<int,int>> lines;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int start,end;
        cin>>start>>end;
        lines.push_back({start, end});
    }
    sort(lines.begin(), lines.end());

    for (int i = 0; i < n; i++) {
        dp[i]=1;
        for (int j = 0; j < i; j++) {
            if (lines[i].second > lines[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout<<n-ans;
}
