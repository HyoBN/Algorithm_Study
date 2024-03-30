#include <iostream>
using namespace std;

int main(){
    int n;
    int cy=100, sd=100;

    cin>>n;
    while (n--) {
        int a,b;
        cin>>a>>b;
        if(a>b) sd-=a;
        else if(a<b) cy-=b;
    }
    cout<<cy<<'\n'<<sd;
}
