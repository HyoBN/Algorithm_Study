#include <iostream>
#include <cstring>
using namespace std;

int height,width;
int map[101][101];
bool visited[101][101];
bool melting_area[101][101];
int y_dir[4]={1,0,-1,0};
int x_dir[4]={0,1,0,-1};

void check_air(int y, int x){
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=y+y_dir[i];
		int nx=x+x_dir[i];
		if(ny>=0 && ny<height && nx>=0 && nx<width){
			if(!visited[ny][nx] && map[ny][nx]==0){
				check_air(ny,nx);
			}
		}
	}
}

int main(){
	int cnt=0;
	bool flag=false;
	int cheeze=0;
	cin>>height>>width;
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
			cin>>map[i][j];
	
	while(true){
		memset(melting_area,false,sizeof(melting_area));
		memset(visited,false,sizeof(visited));
		flag=false;
		
		check_air(0,0);
		for(int i=1;i<height-1;i++){
			for(int j=1;j<width-1;j++){
				if(map[i][j]==1 && !visited[i][j]){
					for(int k=0;k<4;k++){
						int ny=i+y_dir[k];
						int nx=j+x_dir[k];
						if(map[ny][nx]==0 && visited[ny][nx]){
							flag=true;
							melting_area[i][j]=true;
							break;					
						}
					}
				}
			}
		}
		if(!flag) break;
		cheeze=0;
		for(int i=1;i<height-1;i++){
			for(int j=1;j<width-1;j++){
				if(melting_area[i][j]){
					cheeze++;
					map[i][j]=0;
				}
			}
		}
		cnt++;
	}
	cout<<cnt<<endl<<cheeze;
}