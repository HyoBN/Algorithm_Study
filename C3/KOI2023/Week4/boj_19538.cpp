#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int believeTime[200001];
int nowTime=1;
vector<int> neighbor[200001];
queue<int> q;
queue<int> newBeliever;
bool checkBelieve(int people){
    int cnt=0;
    for (int i = 0; i < neighbor[people].size(); i++) {
        if (believeTime[neighbor[people][i]] >= 0) {
            cnt++;
        }
    }
    if (cnt * 2 >= neighbor[people].size()) {
        return true;
    } else
        return false;
}

int main(){
    cin>>n;
    for(int i=0;i<=n;i++){
        believeTime[i]=-1;
    }
    for (int i = 1; i <= n; i++) {
        while (true) {
            int tmp;
            cin>>tmp;
            if(tmp==0) break;
            neighbor[i].push_back(tmp);
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        believeTime[tmp]=0;
        q.push(tmp);
    }

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < neighbor[tmp].size(); i++) {
            int chk = neighbor[tmp][i];
            if(believeTime[chk]==-1 && checkBelieve(chk)){
                newBeliever.push(chk);
            }
        }
        if (q.empty()) {
            while (!newBeliever.empty()) {
                int believer = newBeliever.front();
                q.push(believer);
                newBeliever.pop();
                believeTime[believer] = nowTime;
            }
            nowTime++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout<<believeTime[i]<<" ";
    }
}
