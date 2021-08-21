#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<pair<int,int>> v[5001];
bool visited[5001];

int main() {
	int N, Q;
	scanf("%d %d",&N,&Q);
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	
	for (int i = 0; i < Q; i++) {
		int k, nth;
		scanf("%d %d",&k,&nth);
		memset(visited, false, sizeof(visited));
		visited[nth] = true;
		int cnt = 0;
		queue<int> q;
		q.push(nth);
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i].first;
				int cost = v[now][i].second;
				if (visited[next]) continue; 
				if (cost >= k) {
					cnt++;
					visited[next] = true;
					q.push(next);
				}
			}
		}
		printf("%d\n",cnt);
	}

	return 0;
}