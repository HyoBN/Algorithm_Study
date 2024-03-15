#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    long long result=0;
    double ans=0;
    cin>>n;
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++) {
        long long x,y;
        cin>>x>>y;
        v.push_back({x, y});
    }
    v.push_back({v[0].first, v[0].second});

    for (int i = 0; i < v.size()-1; i++) {
        result += v[i].first * v[i + 1].second;
    }

    for (int i = 0; i < v.size()-1; i++) {
        result -= v[i].second * v[i + 1].first;
    }

    ans = (double)abs(result)/2;
    cout<<fixed;
    cout.precision(1);
    cout<<ans;

}
