import java.util.*;

class Solution {
    
    class info{
        int y;
        int x;
        info(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    final static int[] dy = {0,1,0,-1};
    final static int[] dx = {1,0,-1,0};
    
    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length;
        int m = maps[0].length;
        int[][] dist = new int[n][m];
        
        Queue<info> q = new ArrayDeque<>();
        q.offer(new info(0,0));
        dist[0][0]=1;
        while(!q.isEmpty()){
            info tmp = q.poll();
            int y =tmp.y;
            int x = tmp.x;
            
            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny>=n || ny<0 || nx>=m || nx<0) continue;
                if(maps[ny][nx]!=0 && dist[ny][nx]==0){
                    dist[ny][nx] = dist[y][x]+1;
                    q.offer(new info(ny,nx));
                }
            }
        }
        answer = dist[n-1][m-1];
        if(answer==0) answer=-1;
        return answer;
    }
}
