#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> vec[101];
int visited[101];

void dfs(int i){
	for(int j=0;j<vec[i].size();j++){
		if(!visited[vec[i][j]]){
			visited[vec[i][j]]=1;
			dfs(vec[i][j]);
		}
	}
	
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int tmp;
			cin>>tmp;
			if(tmp) vec[i].push_back(j);
		}
	}
	for(int i=0;i<n;i++){
		memset(visited,0,sizeof(visited));
		dfs(i);
		for(int j=0;j<n;j++)
			cout<<visited[j]<<" ";
		cout<<'\n';
	}
}