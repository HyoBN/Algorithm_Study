#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

bool edge[101][101];
bool visited[101];

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(int i=0;i<wires.size();i++){
        edge[wires[i][0]][wires[i][1]]=true;
        edge[wires[i][1]][wires[i][0]]=true;
    }
    
    for(int i=0;i<wires.size();i++){
        edge[wires[i][0]][wires[i][1]]=false;
        edge[wires[i][1]][wires[i][0]]=false;
        
        memset(visited,false,sizeof(visited));
        visited[wires[i][0]]=true;
        queue<int> q;
        q.push(wires[i][0]);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j=1;j<=n;j++)
            {
                if((edge[node][j] || edge[j][node]) && !visited[j]){
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(visited[j]){
                cnt++;
            }
        }
        answer = min(answer, abs(cnt-(n-cnt)));
        
        edge[wires[i][0]][wires[i][1]]=true;
        edge[wires[i][1]][wires[i][0]]=true;
        
        
    }
    return answer;
}
