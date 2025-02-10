#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int binary[4]={8,4,2,1};

bool visited[51][51];
int map[51][51];
int roomNum[51][51];
int nowRoomNumber=1;

int roomCount,maxRoomSize, maxRoomSumSize;
int totalRoomSize[3000];

struct roomInfo{
    int y;
    int x;
    int wallNum;
};

int mapSearch(roomInfo room){
    int roomSize =1;
    queue<pair<int,int>> q;

    int nowWallNum = room.wallNum;
    q.push({room.y, room.x});

    while (!q.empty()) {
        pair<int,int> tmp = q.front();
        q.pop();
        int y =tmp.first;
        int x = tmp.second;

        roomNum[y][x]=nowWallNum;
        visited[y][x]=true;

        int canMoveValue = 15 - map[y][x];

        for (int i = 0; i < 4; i++) {
            if(canMoveValue - binary[i] >= 0){
                canMoveValue -= binary[i];//1
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny>=m || ny<0 || nx>=n || nx<0) continue;
                if(!visited[ny][nx]) {
                    q.push({ny, nx});
                    visited[ny][nx]=true;
                    roomSize++;
                }

          
        }

    }
    return roomSize;
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]){
                int newRoomSize = mapSearch({i, j, nowRoomNumber});
                totalRoomSize[nowRoomNumber]=newRoomSize;
                nowRoomNumber++;
            }
        }
    }

    roomCount = nowRoomNumber-1;

    for (int i = 1; i <= nowRoomNumber; i++) {
        maxRoomSize = max(maxRoomSize, totalRoomSize[i]);
    }

    vector<pair<int,int>> adjRoomNum;

        // m=1 , n = 3
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if(j+1<n) {
                if (roomNum[i][j] != roomNum[i][j + 1]) {
                    adjRoomNum.push_back({roomNum[i][j], roomNum[i][j + 1]});
                }
            }
            if(i+1<m){
                if(roomNum[i][j]!= roomNum[i+1][j]) {
                    adjRoomNum.push_back({roomNum[i][j], roomNum[i + 1][j]});
                }
            }
        }
    }

    for (int i = 0; i < adjRoomNum.size(); i++) {
        int tmpRoomSumSize = totalRoomSize[adjRoomNum[i].first] + totalRoomSize[adjRoomNum[i].second];

        maxRoomSumSize = max(maxRoomSumSize, tmpRoomSumSize);
    }
    if (adjRoomNum.empty()) {
        maxRoomSumSize=maxRoomSize;
    }
    cout<<roomCount<<endl<<maxRoomSize<<endl<<maxRoomSumSize;

}



