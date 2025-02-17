#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int ans = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1,0,-1,0};

int map[9][9];
bool visited[9][9];
vector<pair<int,int>> virus;
vector<pair<int,int>> emptyArea;

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y, x});

    visited[y][x]=true;
    while (!q.empty()) {
        pair<int,int> tmp = q.front();
        q.pop();

        int y = tmp.first;
        int x= tmp.second;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>=n || ny<0 || nx >=m || nx<0) continue;

            if(map[ny][nx]==0 && !visited[ny][nx]){
                visited[ny][nx]=true;
                q.push({ny, nx});
            }
        }
    }

}

void simulation(int wall1Idx, int wall2Idx, int wall3Idx){
    memset(visited, false, sizeof(visited));

    pair<int,int> wall1 = emptyArea[wall1Idx];
    pair<int,int> wall2 = emptyArea[wall2Idx];
    pair<int,int> wall3 = emptyArea[wall3Idx];

    map[wall1.first][wall1.second]=1;
    map[wall2.first][wall2.second]=1;
    map[wall3.first][wall3.second]=1;

    for (int i = 0; i < virus.size(); i++) {
        bfs(virus[i].first, virus[i].second);
    }

    map[wall1.first][wall1.second]=0;
    map[wall2.first][wall2.second]=0;
    map[wall3.first][wall3.second]=0;
}

int countSafeArea(){
    int safeArea=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                safeArea++;
            }
        }
    }
    return safeArea;
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
            if(map[i][j]==2){
                virus.push_back({i, j});
            }
            else if(map[i][j]==0){
                emptyArea.push_back({i, j});
            }
        }
    }


    for (int i = 0; i < emptyArea.size()-2; i++) {
        for (int j = i+1; j < emptyArea.size()-1; j++){
            for (int k = j+1; k < emptyArea.size(); k++){
                simulation(i, j, k);
                ans = max(ans, countSafeArea()-3);
            }
        }
    }

    cout<<ans;


}
