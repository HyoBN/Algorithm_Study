#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m,ans=2147000000;
    int l = 0, r = 0;
    int arr[100001];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    while(r < n) {
        int sub = arr[r] - arr[l];
        if(sub >= m) {
            ans = min(ans, sub);
            if(ans == m) break;
            l++;
        }
        else r++;
    }
    cout << ans;
}
