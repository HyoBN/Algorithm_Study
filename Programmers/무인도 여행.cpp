#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool visited[101][101];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int mapHeight = maps.size();
    int mapWidth = maps[0].length();
    for(int i=0;i<mapHeight;i++){
        for(int j=0;j<mapWidth;j++){
            char value = maps[i][j];
            if(value!='X' && !visited[i][j]){
                int totalFood=maps[i][j]-'0';
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                while(!q.empty()){
                    pair<int,int> nowDir = q.front();
                    int y = nowDir.first;
                    int x = nowDir.second;
                    
                    q.pop();
                    
                    for(int i=0;i<4;i++){
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(ny >=mapHeight || ny<0 || nx>=mapWidth || nx<0) continue;
                        if(!visited[ny][nx] && maps[ny][nx]!='X'){
                            visited[ny][nx]=true;
                            totalFood += maps[ny][nx]-'0';
                            q.push({ny,nx});
                        }
                    }
                    
                }
                if(totalFood!=0) answer.push_back(totalFood);
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}
