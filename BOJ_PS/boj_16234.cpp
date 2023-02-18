#include <iostream>
#include <cstring>
using namespace std;

int n,l,r,pointer;
int peopleAmount,countryAmount;
bool visited[51][51];
int map[51][51];
int population[10000001];
int y_dir[] = {1, 0, -1, 0};
int x_dir[] = {0, 1, 0, -1};
bool flag=true;
int ans=0;

void dfs(int y, int x){
    visited[y][x]=true;
    peopleAmount+=map[y][x];
    countryAmount++;
    for (int i = 0; i < 4; i++) {
        int ny = y + y_dir[i];
        int nx = x + x_dir[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
            int gap = abs(map[ny][nx]-map[y][x]);
            if (gap >= l && gap <= r && !visited[ny][nx]) {
                flag=true;
                dfs(ny, nx);
            }
        }
    }
    map[y][x]=pointer;
}
int main(){
    cin>>n>>l>>r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    while(flag) {
        flag=false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                peopleAmount = 0, countryAmount = 0;
                if (!visited[i][j]) {
                    dfs(i, j);
                    population[pointer] = peopleAmount / countryAmount;
                    pointer++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = population[map[i][j]];
            }
        }
        if(flag) ans++;
    }
    cout<<ans;
}
