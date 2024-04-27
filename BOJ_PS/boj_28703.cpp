#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


priority_queue<long long, vector<long long>, greater<long long>> pq;
long long minValue = 1000000001, maxValue=0;
long long minDiff, inputMaxValue;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin>>tmp;
        minValue = min(minValue, tmp);
        maxValue = max(maxValue, tmp);
        pq.push(tmp);
    }
    minDiff = maxValue - minValue;
    inputMaxValue=maxValue;

    while(true){
        long long nowValue = pq.top();
        pq.pop();

        long long nowDiff = maxValue - nowValue;
        minDiff = min(minDiff, nowDiff);

        if(inputMaxValue<nowValue) break;
        nowValue*=2;
        maxValue = max(nowValue, maxValue);
        pq.push(nowValue);
    }
    cout<<minDiff;
}
