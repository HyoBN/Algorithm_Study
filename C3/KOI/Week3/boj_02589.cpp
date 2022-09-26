#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct treasure {
	int x, y, d;
};

int n, m;
char a[51][51];
bool check[51][51];
int y_dir[] = { 0,1,0,-1 };
int x_dir[] = { 1,0,-1,0 };

int bfs(int i, int j) {
	int dist = 0;
	queue<treasure> q;
	q.push({ i,j,0 });
	check[i][j] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + x_dir[k];
			int ny = y + y_dir[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!check[nx][ny] && a[nx][ny] == 'L') {
					q.push({ nx,ny,d + 1 });
					check[nx][ny] = true;
					dist = max(dist, d + 1);
				}
			}
		}
	}
	return dist;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				memset(check, false, sizeof(check));
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans;

}
