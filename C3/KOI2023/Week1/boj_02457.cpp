#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<int,int> pii;
using namespace std;

int month[13]={0,0,31,59,90,120,151,
               181,212,243,273,304,334};

bool cmp1(pii p1, pii p2){
    if(p1.first==p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

bool cmp2(pii p1, pii p2){
    return p1.second > p2.second;
}

int main(){
    int n,ans=1;
    vector<pii> flowers;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int m1,d1,m2,d2;
        cin>>m1>>d1>>m2>>d2;
        flowers.push_back({month[m1] + d1, month[m2] + d2});
    }

    sort(flowers.begin(), flowers.end(),cmp2);

    if(flowers[0].second < month[12+1]){
        cout<<0;
        return 0;
    }
    sort(flowers.begin(), flowers.end(),cmp1);
    if(flowers[0].first > month[3]+1){
        cout<<0;
        return 0;
    }

    int idx=0;
    for (int i = 1; i < n; i++) {
        pii tmp = flowers[i];
        if(tmp.first<=(month[3]+1) && tmp.second > flowers[idx].second)
            idx=i;
    }

    while (true) {
        if (flowers[idx].second > (month[11] + 30)) break;
        pii last = {1, 1};
        int lastIdx = -1;
        for (int i = idx + 1; i < n; i++) {
            pii tmp = flowers[i];
            if (tmp.first <= flowers[idx].second && tmp.second > last.second){
                last = tmp;
                lastIdx = i;
            }
        }
        idx = lastIdx;
        if(last.first==1) {
            cout<<0;
            return 0;
        }
        else ans++;
    }
    cout<<ans;
}
