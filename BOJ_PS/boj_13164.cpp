#include <iostream>
#include <algorithm>
using namespace std;

int arr[300001];
int height[300001];
int main() {
    int n, k, ans = 0;
    cin>>n>>k;

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    for (int i = 0; i < n - 1; i++) {
        arr[i] = height[i + 1] - height[i];
    }
    sort(arr, arr + n - 1);

    for (int i = 0; i < n - k; i++) {
        ans += arr[i];
    }
    cout<<ans;
}
