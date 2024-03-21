#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    priority_queue<pair<int,pair<int,int>>> pq;

    int t,n;
    cin>>t>>n;
    while (n--) {
        int id,leftTime,priority;
        cin >> id >> leftTime >> priority;
        pq.push({priority, {id * -1, leftTime}});
    }
    while (t > 0 && !pq.empty()) {
        int sId = pq.top().second.first;
        int sLeftTime = pq.top().second.second;
        int sPriority = pq.top().first;
        pq.pop();
        cout << sId * -1 << '\n';
        if (sLeftTime > 1) {
            pq.push({sPriority - 1, {sId, sLeftTime - 1}});
        }
        t--;
    }
}
