#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int map[501][501];
bool visited[501][501];
int y_dir[4] = { 1,0,-1,0 };
int x_dir[4] = { 0,1,0,-1 };
int n,m,ans = 0;

void dfs(int y, int x, int area, int count) {
	
	if (count >= 4) {
		ans = max(ans, area);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + y_dir[i];
		int nx = x + x_dir[i];
		if (ny < n && nx < m && ny>=0 && nx>=0) {
			if (!visited[ny][nx]) {
				visited[y][x] = true;
				dfs(ny, nx, area + map[ny][nx], count + 1);
				visited[y][x] = false;
			}
		}
	}
}

void check(int y, int x) {
	int tmp = 0;
	if (y >= 1 && x >= 1 && x < m - 1)
		ans = max(ans, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y][x + 1]);
	if (y >= 1 && y < n - 1 && x < m - 1)
		ans = max(ans, map[y - 1][x] + map[y][x] + map[y][x + 1] + map[y + 1][x]);
	if (y >= 0 && y < n - 1&& x < m - 1)
		ans = max(ans, map[y][x - 1] + map[y][x] + map[y + 1][x] + map[y][x + 1]);
	if (y >= 1 && y < n - 1&& x >= 1)
		ans = max(ans, map[y - 1][x] + map[y][x] + map[y][x - 1] + map[y + 1][x]);

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			dfs(i, j, map[i][j], 1);
			check(i, j);
		}
	}
	cout << ans;
}
