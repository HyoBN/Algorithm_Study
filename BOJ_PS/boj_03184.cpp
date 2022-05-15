#include <iostream>
using namespace std;

char map[251][251];
bool visited[251][251];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};

int r,c;
int total_sheep_cnt=0, total_wolf_cnt=0;
int sheep_tmp=0, wolf_tmp=0;

void dfs(int y,int x){
	visited[y][x]=true;
	if(map[y][x]=='v') wolf_tmp++;
	else if(map[y][x]=='o') sheep_tmp++;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<r && nx>=0 && nx<c){
			if(map[ny][nx]!='#' && !visited[ny][nx])
				dfs(ny,nx);
		}
	}
}

int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>map[i][j];
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j]!='#' && !visited[i][j]){
				sheep_tmp=0, wolf_tmp=0;
				dfs(i,j);

				sheep_tmp>wolf_tmp ? total_sheep_cnt+=sheep_tmp : total_wolf_cnt+=wolf_tmp;
			}
		}
	}
	cout<<total_sheep_cnt<<' '<<total_wolf_cnt;
	
}