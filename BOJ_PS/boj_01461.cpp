#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> minus;
    vector<int> plus;

    for (int i = 0; i < n; i++) {
        int book;
        cin >> book;
        if(book<0)
            minus.push_back(book);
        else plus.push_back(book);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());


    int ans=0;
    for (int i = 0; i < minus.size(); i+=m) {
        if(i>=minus.size()) break;
        ans+= (minus[i]*-1)*2;
    }
    for (int i = plus.size()-1; i >= 0; i -= m) {
        if(i<0) break;
        ans += plus[i]*2;
    }
    if(minus.empty()) ans -= plus[plus.size() - 1];
    else if(plus.empty()) ans -= abs(minus[0]);
    else ans -= max(abs(minus[0]), plus[plus.size() - 1]);

    cout<<ans;
}
