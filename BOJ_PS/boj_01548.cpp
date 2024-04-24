#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,ans=1;
    long long arr[51];
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if(j<=i+1) break;
            if (arr[i] + arr[i + 1] > arr[j]) {
                ans = max(ans, j - i + 1);
                break;
            }
        }
    }
    if(ans==1 && n>=2) ans=2;
    cout<<ans;
}
