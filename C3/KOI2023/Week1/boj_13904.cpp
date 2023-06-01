#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> v1, pair<int, int> v2){
    return v1.second>=v2.second;
}
bool check[1001];

int possibleDate(int deadline){
    for (int i = deadline; i >= 1; i--) {
        if(!check[i]){
            check[i]=true;
            return i;
        }
    }
    return -1;
}

int main(){
    int n,ans=0;
    vector<pair<int,int>> v;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int d,w;
        cin>>d>>w;
        v.push_back({d, w});
    }
    sort(v.begin(), v.end(), cmp);

    for (auto homework: v) {
        int date = possibleDate(homework.first);
        if(date==-1) continue;
        ans+=homework.second;
    }

    cout<<ans;
}
