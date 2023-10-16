#include <iostream>
using namespace std;

char balls[500001];
int r_cnt,b_cnt;
int l=1,r=1;
int ans=0;


int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
        balls[i] == 'R' ? r_cnt++ : b_cnt++;
    }
    ans = min(r_cnt, b_cnt);
    for (int i = 1; i < n; i++) {
        if(balls[i]==balls[0]) l++;
        else break;
    }
    for (int i = n - 2; i >= 0; i--) {
        if(balls[i]==balls[n-1]) r++;
        else break;
    }
    ans = min(ans,balls[0]=='R' ? r_cnt-l : b_cnt-l);
    ans = min(ans, (balls[n - 1] == 'R' ? r_cnt - r : b_cnt - r));
    cout<<ans;

}
