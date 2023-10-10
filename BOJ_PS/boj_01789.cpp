#include <iostream>
using namespace std;

int main(){
    long long int s;
    long long int now=0;
    int cnt=0;
    cin>>s;

    for (long long int i = 1; i <= s; i++) {
        if(now>s) break;
        now+=i;
        cnt++;
    }
    if(s==1) cnt++;
    cout<<cnt-1;
}
