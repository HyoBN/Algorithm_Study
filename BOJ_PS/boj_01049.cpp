#include <iostream>
using namespace std;

int main(){
    int n,m;
    int set=9999,one=9999;
    cin>>n>>m;
    
    while (m--) {
        int x,y;
        cin>>x>>y;
        set=min(set,x);
        one=min(one,y);
    }
    cout<<min((n/6+1)*set, min(n/6*set + n%6*one, n*one));
}
