#include <iostream>
using namespace std;

char ch[20001];
int main() {
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin >> ch[i];
    }

    for (int i = 0; i < n; i++) {
        if (ch[i] == 'P') {
            for (int j = i - k; j <= i + k; j++) {
                if(j<0 || j>n-1) continue;
                if(ch[j]=='H') {
                    ch[j]='X';
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;

}
