#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m,n,h;
int map[101][101][101];
int z_dir[6]={0,0,0,0,1,-1};
int y_dir[6]={1,0,-1,0,0,0};
int x_dir[6]={0,1,0,-1,0,0};

struct coordinate{
	int z,y,x;
};

int main(){
	int ans=0;
	queue<coordinate> q;
	cin>>m>>n>>h;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				int tmp;
				cin>>tmp;
				map[i][j][k]=tmp;
				if(tmp==1) q.push({i,j,k});
			}
		}
	}
	while(!q.empty()){
		int z=q.front().z;
		int y=q.front().y;
		int x=q.front().x;
		for(int i=0;i<6;i++){
			int nz=z+z_dir[i];
			int ny=y+y_dir[i];
			int nx=x+x_dir[i];
			if(nz>=0 && nz<h && ny>=0 && ny<n && nx>=0 && nx<m ){
				if(map[nz][ny][nx]==0){
					map[nz][ny][nx]=map[z][y][x]+1;
					ans=max(ans,map[nz][ny][nx]-1);
					q.push({nz,ny,nx});
				}
			}
		}
		q.pop();
	}
		
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(map[i][j][k]==0){
					ans=-1;
				}
			}
		}
	}
	cout<<ans;
}