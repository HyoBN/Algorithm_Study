#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> v;
int main(){
    int n, l, ans=0,tmp=0;
    cin >> n >> l;

    while(n--){
        int x,y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if(tmp >= v[i].second) continue;
        tmp = max(tmp, v[i].first);
        int cnt = (v[i].second - (tmp + 1)) / l + 1;
        ans+=cnt;
        tmp += cnt * l;
    }
    cout<<ans;

}
