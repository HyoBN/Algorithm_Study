#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int map[501][501];
int n,m;
int oilNum=2;
int oilSizeArr[200000];

void dfs(int y, int x, int oilSize){
    map[y][x]=oilNum;
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
    
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        
        if(map[ny][nx]==1){
            oilSizeArr[oilNum]++;
             dfs(ny,nx,oilSize+1);
        }
    }
}

void updateMap(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==1){
                oilSizeArr[oilNum]=1;
                dfs(i,j,1);;
                oilNum++;
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n=land.size();
    m=land[0].size();
        
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]=land[i][j];
        }
    }
    
    updateMap();
    
    for(int i=0;i<m;i++){
        bool visited[200000];
        int totalOil=0;
        memset(visited,false,sizeof(visited));
        for(int j=0;j<n;j++){
            if(map[j][i]!=0){
                int nowOilNum=map[j][i];
                if(visited[nowOilNum]==false){
                    visited[nowOilNum]=true;
                    totalOil+=oilSizeArr[nowOilNum];
                }
                
            }
        }
        answer=max(answer,totalOil);
    }
    
    return answer;
}
