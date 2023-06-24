#include <iostream>
#include <queue>
using namespace std;

char board[22][22];
int n, m, c1x, c1y, c2x, c2y;
string s;
int visited[22][22][22][22] = {0, };
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

struct info { int x1, y1, x2, y2, cnt; };

bool rangeOver(int x, int y)
{
    if((0 <= x && x < n) && (0 <= y && y < m)){
        return true;
    }
    return false;
}

int main()
{
    cin>>n>>m;
    int num = 0;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            board[i][j] = s[j];
            if(board[i][j]=='o'){
                board[i][j] = '.';
                if(num==0){
                    c1x = i;
                    c1y = j;
                    num++;
                }
                if(num==1){
                    c2x = i;
                    c2y = j;
                }
            }
        }
    }

    queue<info> q;
    q.push({c1x, c1y, c2x, c2y, 0 });

    while(!q.empty()){
        info cur = q.front();
        visited[cur.x1][cur.y1][cur.x2][cur.y2] = 1;
        q.pop();
        if(cur.cnt>10){
            break;
        }

        for(int i=0; i<4; i++){
            int nx1 = cur.x1 + x_dir[i];
            int ny1 = cur.y1 + y_dir[i];
            int nx2 = cur.x2 + x_dir[i];
            int ny2 = cur.y2 + y_dir[i];

            if((rangeOver(nx1, ny1) && !rangeOver(nx2, ny2)) || (!rangeOver(nx1, ny1) && rangeOver(nx2, ny2))){
                if(cur.cnt+1>10){
                    cout<< -1;
                    return 0;
                }
                cout<< cur.cnt+1;
                return 0;
            }

            if(!rangeOver(nx1, ny1) && !rangeOver(nx2, ny2)){
                continue;
            }

            if(board[nx1][ny1]=='#' && board[nx2][ny2]=='#'){
                continue;
            }

            if(board[nx1][ny1]=='#'){
                nx1 = cur.x1;
                ny1 = cur.y1;
            }else if(board[nx2][ny2]=='#'){
                nx2 = cur.x2;
                ny2 = cur.y2;
            }

            if(!visited[nx1][ny1][nx2][ny2]){
                q.push({ nx1, ny1, nx2, ny2, cur.cnt+1});
                visited[nx1][ny1][nx2][ny2] = true;
            }
        }
    }
    cout<< -1;
}
