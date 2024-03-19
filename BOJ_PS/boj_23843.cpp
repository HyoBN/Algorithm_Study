#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main()
{

    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v;

    for (int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < min(m,n); i++)
        pq.push(v[i]);

    for (int i = m; i < n; i++)
    {
        int top = pq.top();
        pq.pop();
        pq.push(v[i] + top);
    }

    while (pq.size() != 1)
        pq.pop();

    cout << pq.top() << '\n';
}
