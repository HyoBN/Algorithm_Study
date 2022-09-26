#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, k, a, b;
vector<int> g[1010];
int main() {
	cin >> n >> k;
	vector<string> v(n + 1);
	queue<int> q;
	vector<int> d(n + 1, -1);
	vector<int> p(n + 1);
	vector<int> ans;

	for (int i = 1; i <= n; i++)
		cin >> v[i];
	cin >> a >> b;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int x = 0;
			for (int l = 0; l < k; l++) {
				if (v[i][l] != v[j][l]) x++;
			}

			if (x == 1) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	q.push(a);
	d[a] = 0;
	p[a] = a;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == b) break;
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i];
			if (d[next] == -1) {
				q.push(next);
				d[next] = d[now] + 1;
				p[next] = now;
			}
		}
	}

	ans.push_back(b);
	int node = b;
	while (p[node] != node) {
		node = p[node];
		ans.push_back(node);
	}

	if (ans.back() != a) cout << -1;
	else {
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << " ";
	}
}
