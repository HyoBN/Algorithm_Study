#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main(){
    vector<pair<int,int>> v;
    int n, ans=2147000000;

    cin>>n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = n - 1; i >= 0; i--) {
        ans = min(ans, v[i].second);
        ans -= v[i].first;
    }
    if(ans<0) cout<<-1;
    else cout<<ans;
}
