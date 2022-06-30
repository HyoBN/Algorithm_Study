#include <iostream>
#include <queue>
using namespace std;

bool visited[10001];
int main(){
	int n,m;
	int a,b,c;
	int ans=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<pair<int,int>> p[10001];
	cin>>n;
	cin>>m;
	
	while(m--){
		cin>>a>>b>>c;
		p[a].push_back({c,b});
		p[b].push_back({c,a});
	}
	pq.push({0,1});
	
	while(!pq.empty()){
		pair<int,int> tmp=pq.top();
		pq.pop();
		int node=tmp.second;
		int cost=tmp.first;
		if(!visited[node]){
			ans+=cost;
			visited[node]=true;
			for(int i=0;i<p[node].size();i++){
				pq.push(p[node][i]);
			}
		}
	}
	cout<<ans;
}
