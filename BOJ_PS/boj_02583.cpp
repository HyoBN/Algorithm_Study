#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101];
bool visited[101][101];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};
int area[10201];
int cnt=0;
int m,n,k;

void dfs(int y, int x){
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<m && nx>=0 && nx<n){
			if(map[ny][nx]==0 && !visited[ny][nx]){
				area[cnt-1]++;
				dfs(ny,nx);
			}
		}
	}
}

int main(){
	cin>>m>>n>>k;
	
	for(int i=0;i<k;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=m-y2;j<m-y1;j++) //y축 뒤집기
			for(int l=x1;l<x2;l++){
				map[j][l]=1;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==0 && !visited[i][j]){
				cnt++;
				dfs(i,j);
			}
		}
	}
	sort(area,area+cnt);
	
	cout<<cnt<<'\n';
	for(int i=0;i<cnt;i++)
		cout<<area[i]+1<<" "; // dfs 시작점도 count 하기위해 +1
}