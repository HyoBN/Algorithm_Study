#include <iostream>
#include <vector>
using namespace std;

int n,ansCnt=1000001;
vector<int> v;
vector<int> ansVector;

void dfs(int x, int cnt){
    if(cnt>ansCnt) return;
    if(x==1){
        if(cnt<=ansCnt){
            ansCnt=cnt;
            ansVector=v;
        }
        return;
    }
    if(x%3==0){
        v.push_back(x/3);
        dfs(x/3, cnt+1);
        v.pop_back();
    }
    if(x%2==0){
        v.push_back(x/2);
        dfs(x/2,cnt+1);
        v.pop_back();
    }
    v.push_back(x-1);
    dfs(x-1,cnt+1);
    v.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    v.push_back(n);
    dfs(n, 0);
    cout << ansCnt << "\n";
    for (int i = 0; i < ansVector.size(); i++) {
        cout<<ansVector[i]<<' ';
    }
}
