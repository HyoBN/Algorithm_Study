#include <iostream>
using namespace std;

int n, m;
int map[51][51];
bool visited[51][51];
int r, c, d;
int cnt = 1;
int x_dir[] = { 0,1,0,-1 };
int y_dir[] = { -1,0,1,0 };

void cleaning(int y, int x, int dir) {
	bool canMove = false;
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int nextDir = (dir + 3 - i) % 4;
		int leftY = y + y_dir[nextDir];
		int leftX = x + x_dir[nextDir];
		if (leftY >= 0 && leftY < n && leftX >= 0 && leftX < m) {
			if (!map[leftY][leftX] && !visited[leftY][leftX]) {
				canMove = true;
				cnt++;
				cleaning(leftY, leftX, nextDir);
			}
		}
	}
	if (!canMove) {
		int backDir = (dir + 2) % 4;
		int backY = y + y_dir[backDir];
		int backX = x + x_dir[backDir];
		if (backY >= 0 && backY < n && backX >= 0 && backX < m) {
			if (!map[backY][backX])
				cleaning(backY, backX, dir);
			else {
				cout << cnt;
				exit(0);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	cleaning(r, c, d);
	cout << cnt;

}
