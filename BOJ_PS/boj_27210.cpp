#include <iostream>
using namespace std;

int n,cnt,maxx,minn;
int main(){
    cin>>n;
    while (n--) {
        int stone;
        cin>>stone;
        if(stone==1) cnt++;
        else cnt--;
        maxx=max(maxx, cnt);
        minn = min(minn, cnt);
    }

    cout<<maxx-minn;
}
