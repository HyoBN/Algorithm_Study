#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n,k,leftColor=-1;
    int colorMaxCnt=0;
    priority_queue<pair<int,int>> pq;

    cin>>n>>k;

    for (int i = 1; i <= k; i++) {
        int cnt;
        cin>>cnt;
        pq.push({cnt, i});
        colorMaxCnt = max(colorMaxCnt, cnt);
    }

    if (colorMaxCnt > ceil((double)n / 2)) {
        cout<<-1;
    }else{
        while(!pq.empty()) {
            pair<int, int> tmp = pq.top();
            pq.pop();
            if(tmp.second==leftColor) {
                pair<int, int> tmp2 = pq.top();
                pq.pop();
                cout<< tmp2.second<<' ';
                leftColor=tmp2.second;
                pq.push(tmp);
                if(tmp2.first>1)
                    pq.push({tmp2.first - 1, tmp2.second});

            }else {
                cout << tmp.second << ' ';
                leftColor = tmp.second;
                if (tmp.first > 1)
                    pq.push({tmp.first - 1, tmp.second});
            }
        }
    }


}
