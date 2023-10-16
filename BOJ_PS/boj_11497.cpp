#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int l[100001];
int main(){
    cin>>t;
    while (t--) {
        int ans=0;
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>l[i];
        }
        sort(l, l + n);

        for (int i = 2; i < n; i += 2) {
            ans = max(ans, abs(l[i] - l[i - 2]));
        }
        for (int i = 3; i < n; i += 2) {
            ans = max(ans, abs(l[i] - l[i - 2]));
        }
        ans = max(ans, abs(l[n - 1] - l[n - 2]));
        cout<<ans<<endl;
    }
}
