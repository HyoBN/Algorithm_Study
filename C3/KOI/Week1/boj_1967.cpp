#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n;
int visited[10002] = { 0 };
vector<pair<int, int>> node[10002];

int ans = 0;
int end_point = 0;
void dfs(int point, int length) {
	if (visited[point])
		return;

	visited[point] = 1;
	if (ans < length) {
		ans = length;
		end_point = point;
	}

	for (int i = 0; i < node[point].size(); i++)
		dfs(node[point][i].first, length + node[point][i].second);


}


int main() {
	cin >> n;
	int parent, child, length;
	for (int i = 0; i < n - 1; i++) {
		cin >> parent >> child >> length;
		node[parent].push_back({ child,length });
		node[child].push_back({ parent,length });
	}
	dfs(1, 0);
	ans = 0;
	memset(visited, 0, sizeof(visited));

	dfs(end_point, 0);
	cout << ans << endl;
	return 0;
}
