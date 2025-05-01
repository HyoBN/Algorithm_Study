import java.util.*;
class Solution {
    
    public class Info{
        int y;
        int x;
        
        Info(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    int n,m;
    int[] dx = {0,1,0,-1};
    int[] dy = {1,0,-1,0};
    boolean[][] visited;
    char[][] map;
    
    public int[] solution(String[] maps) {
        n = maps.length;
        m = maps[0].length();
        List<Integer> list = new ArrayList<>();
        
        visited = new boolean[n][m];
        map = new char[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[i][j]=maps[i].charAt(j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && map[i][j]!='X'){
                    int totalFood=0;
                    visited[i][j]=true;
                    Queue<Info> q = new ArrayDeque<>();
                    q.offer(new Info(i,j));
                    while(!q.isEmpty()){
                        Info tmp = q.poll();
                        totalFood += (map[tmp.y][tmp.x]-'0');
                        for(int k=0;k<4;k++){
                            int ny = tmp.y + dy[k];
                            int nx = tmp.x + dx[k];
                            if(ny>=n || ny<0 || nx>=m || nx<0) continue;
                            if(!visited[ny][nx] && map[ny][nx]!='X'){
                                visited[ny][nx]=true;
                                q.offer(new Info(ny,nx));
                            }
                        }
                    }
                    list.add(totalFood);
                }
            }
        }
        
        Collections.sort(list);
        
        int[] answer = new int[list.size()];
        for(int i=0;i<answer.length;i++){
            answer[i]=list.get(i);
        }
        if(answer.length==0) answer = new int[]{-1};
        
        return answer;
    }
}
