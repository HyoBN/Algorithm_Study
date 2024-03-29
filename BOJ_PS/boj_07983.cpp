#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main() {
    int n, d, t;
    cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        cin >> d >> t;
        v.push_back({d, t});
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = v[0].second;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        if(v[i].second < cnt) cnt = v[i].second;
        cnt -= v[i].first + tmp;
    }

    if(cnt < 0) cnt=0;
    cout << cnt;
}
