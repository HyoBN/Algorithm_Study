#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int main(){
    int r,c,paperCnt;
    int maxH=0;
    int wrongPaintCnt;
    vector<pair<int, int>> wrongPaint;
    cin>>r>>c;
    cin >> paperCnt;
    cin >> wrongPaintCnt;

    for (int i = 0; i < wrongPaintCnt; i++) {
        int a,b;
        cin>>a>>b;
        maxH = max(maxH, a);
        wrongPaint.push_back({a, b});
    }

    sort(wrongPaint.begin(),wrongPaint.end(),cmp);

    int left=maxH, right=1000001;
    int mid,ans=right;

    while(left<=right){
        mid=(left+right)/2;
        int paperCntTmp=1;
        int columnTmp=wrongPaint[0].second;

        for (int i = 1; i < wrongPaintCnt; i++) {
            if (wrongPaint[i].second >= columnTmp + mid) {
                paperCntTmp++;
                columnTmp = wrongPaint[i].second;
            }
        }

        if(paperCntTmp <= paperCnt){
            ans=mid;
            right=mid-1;
        }else{
            left = mid + 1;
        }
    }
    cout<<ans;
}
