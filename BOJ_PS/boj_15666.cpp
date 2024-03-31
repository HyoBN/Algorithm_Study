#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> v;
int output[8];
bool visited[10001];

void backTracking(int nowValue, int cnt){
    if(cnt==m){
        for (int i = 0; i < m; i++) {
            cout<<output[i]<<' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if(nowValue<=v[i]) {
            output[cnt] = v[i];
            backTracking(v[i], cnt + 1);
        }
    }
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        if(!visited[tmp]){
            v.push_back(tmp);
            visited[tmp]=true;
        }
    }
    sort(v.begin(), v.end());
    backTracking(0,0);
}
