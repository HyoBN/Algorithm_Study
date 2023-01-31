#include <iostream>
#include <algorithm>
using namespace std;
int n, c, m;
int truckCapacity[2001];
pair<pair<int, int>, int> arr[10001]; 

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if (a.first.second < b.first.second)
        return true;
    else if (a.first.second == b.first.second)
        if (a.first.first < b.first.first)
            return true;
    return false;
}

int main(){
    cin >> n >> c >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    sort(arr, arr + m, cmp);
    int ans = 0;

    for (int i = 0; i < m; i++){
        int boxCnt = 0;
        for (int j = arr[i].first.first; j < arr[i].first.second; j++)
            boxCnt = max(boxCnt, truckCapacity[j]);

        int truckLeftSpace = min(arr[i].second, c - boxCnt);
        ans += truckLeftSpace;

        for (int j = arr[i].first.first; j < arr[i].first.second; j++)
            truckCapacity[j] += truckLeftSpace;
    }
    cout << ans;
}
