#include <iostream>
#include <vector>
using namespace std;

vector<int> v[13];
int main(){
    int x,y;
    for (int i = 0; i < 12; i++) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= 12; i++) {
        int cnt=0;
        if(v[i].size()==3){
            for (int j = 0; j < v[i].size(); j++) {
                cnt += v[v[i][j]].size();
            }
        }
        if(cnt==6){
            cout<<i;
            break;
        }
    }
}
