#include <iostream>
#include <vector>
using namespace std;

int building[51];
int cnt[51];

int main(){
    int n,ans=0;
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }

    for (int i = 0; i < n; i++) {
        double maxLevel = -9999999999;
        for (int j = i + 1; j < n; j++) {
            double level = (double) (building[j] - building[i]) / (j - i);
            if(level > maxLevel) {
                cnt[i]++;
                cnt[j]++;
                maxLevel=level;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, cnt[i]);
    }

    cout<<ans;

}
