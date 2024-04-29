#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second>b.second){
        return true;
    }
    else if(a.second==b.second){
        return a.first<b.first;
    } else return false;
}

int main(){
    int n;
    int ans;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(),v.end(),cmp);

    ans = v[0].second - v[0].first;
    for (int i = 1; i < n; i++) {
        if(ans > v[i].second){
            ans = v[i].second - v[i].first;
        } else
            ans -= v[i].first;
    }
    if(ans < 0) ans = -1;
    cout << ans;
}
