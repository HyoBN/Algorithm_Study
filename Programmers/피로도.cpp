#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> dungeonV;
int dungeonsCount=0;
bool visited[9];

void dfs(int somodo, int cnt){
    dungeonsCount = max(dungeonsCount,cnt);
    
    for(int i=0;i<dungeonV.size();i++){
        if(visited[i]) continue;
        else if(dungeonV[i][0]<=somodo){
            visited[i]=true;
            dfs(somodo-dungeonV[i][1], cnt+1);
            visited[i]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeonV = dungeons;
    for(int i=0;i<dungeons.size();i++){
        if(dungeons[i][0]<=k){
            memset(visited,false, sizeof(visited));
            visited[i]=true;
            dfs(k-dungeons[i][1],1);
        }
    }
    return dungeonsCount;
}
