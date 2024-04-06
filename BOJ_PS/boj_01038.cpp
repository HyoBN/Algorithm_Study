#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

void backtracking(string s){
    if(s > "9876543210") return;
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    v.push_back(stoll(tmp));
    for(int i=s.back() - '0' + 1; i<10; i++){
        string num = to_string(i);
        backtracking(s + num);
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<10; i++){
        string num = to_string(i);
        backtracking(num);
    }
    sort(v.begin(), v.end());

    if(v.size()<=n) {
        cout << -1;
    } else cout<<v[n];
}
