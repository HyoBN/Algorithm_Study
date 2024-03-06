#include <iostream>
using namespace std;

int main(){
    int n,a,b;
    int ans=0;
    cin >> n >> a >> b;
    while (a != b) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ans++;
    }
    cout<<ans;
}
