#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, r1, r2;
vector<pair<int, int>> v[100001];
bool visited[100001];
bool flag;

void dfs(int start, int summ, int maxx) {
	if (start == r2) {
		cout << summ - maxx;
		return;
	}

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i].first;
		int dist = v[start][i].second;
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, summ + dist, max(dist, maxx));
		}
	}
	return;
}

int main() {
	cin >> n >> r1 >> r2;
	for (int i = 0; i < n - 1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y, z });
		v[y].push_back({ x,z });
	}
	visited[r1] = true;
	dfs(r1, 0, 0);
}
