#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,x;
vector<int> bigger[100001];
vector<int> smaller[100001];
bool visited[100001];

int main(){
    cin>>n>>m>>x;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        bigger[a].push_back(b);
        smaller[b].push_back(a);
    }
    queue<int> q;
    int biggerCnt=0;
    visited[x]=true;
    q.push(x);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < bigger[tmp].size(); i++) {
            int x = bigger[tmp][i];
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
                biggerCnt++;
            }
        }
    }

    int smallerCnt=0;
    q.push(x);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < smaller[tmp].size(); i++) {
            int x = smaller[tmp][i];
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
                smallerCnt++;
            }
        }
    }

    cout<<1+smallerCnt<<" "<<n-biggerCnt;

}
