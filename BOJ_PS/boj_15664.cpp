#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> v;
int output[8];
bool visited[8];

void backTracking(int nowIdx, int cnt){
    if(cnt==m){
        for (int i = 0; i < m; i++) {
            cout<<output[i]<<' ';
        }
        cout << '\n';
        return;
    }

    int chk=0;
    for (int i = nowIdx; i < v.size(); i++) {
        if(!visited[i] && v[i] != chk) {
            output[cnt] = v[i];
            chk=output[cnt];
            visited[i]=true;
            backTracking(i, cnt + 1);
            visited[i]=false;
        }
    }
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    backTracking(0,0);
}
