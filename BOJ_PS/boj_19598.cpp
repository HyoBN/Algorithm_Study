#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    priority_queue<int,vector<int>,greater<int>>result;
    cin>>n;
    while (n--) {
        int s,e;
        cin>>s>>e;
        pq.push({s,e});
    }

    result.push(pq.top().second);
    pq.pop();

    while(!pq.empty())
    {
        if (pq.top().first >= result.top()) {
            result.push(pq.top().second);
            result.pop();
        } else result.push(pq.top().second);
        pq.pop();
    }
    cout<<result.size();
}
