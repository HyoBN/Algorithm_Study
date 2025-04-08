#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


struct info{
    int y,x;
    int moveCnt;
    
    info(int y, int x, int moveCnt) : y(y), x(x), moveCnt(moveCnt){}
    
};

bool visited[101][101];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int height,width;

int solution(vector<string> board) {
    int answer = 0;
    height = board.size();
    width = board[0].length();
    pair<int,int> start,end;
    queue<info> q;
    bool exitFlag=false;
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]=='R') start={i,j};
            if(board[i][j]=='G') end={i,j};
        }
    }
    q.push(info(start.first, start.second, 0));
    visited[start.first][start.second]=true;
    while(!q.empty()){
        if(exitFlag) break;
        info tmp = q.front();
        q.pop();
        int y = tmp.y;
        int x = tmp.x;
        int moveCount = tmp.moveCnt;
        
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            while(true){
                if(ny>=height || ny<0 || nx>=width || nx<0) break;
                else if(board[ny][nx]=='D') break;
                ny+=dy[i];
                nx+=dx[i];
            }
            ny-=dy[i],  nx-=dx[i];
            
            if(ny ==end.first && nx ==end.second){
                answer = moveCount+1;
                exitFlag=true;
                break;
            }
            if((y==ny && x==nx) || visited[ny][nx])  continue;
            
            else{
                visited[ny][nx]=true;
                q.push(info(ny,nx,moveCount+1));
            }
        }
    }
    if(answer==0) answer=-1;
    
    
    return answer;
}
