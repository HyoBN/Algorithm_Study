#include <iostream>
#include <cstring>
using namespace std;

int x_dir[] = { 0,1,0,-1 };
int y_dir[] = { 1,0,-1,0 };
int n, m, ans;
int map[101][101];
bool air[101][101];
bool meltPoint[101][101];

void airCheck(int y, int x) {
	air[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + y_dir[i];
		int nx = x + x_dir[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
			if (map[ny][nx] == 0 && !air[ny][nx]) {
				airCheck(ny, nx);
			}
		}
	}
}
void meltPointCheck(int y, int x) {
	if (map[y][x] == 1) {
		int airCnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + y_dir[i];
			int nx = x + x_dir[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (air[ny][nx]) airCnt++;
			}
		}
		if (airCnt >= 2) meltPoint[y][x] = true;
	}
}
bool meltCheese() {
	bool continueMelt = false;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (map[i][j]==1 && meltPoint[i][j]) {
				continueMelt = true;
				map[i][j] = 0;
			}
		}
	}
	return continueMelt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (true) {
		memset(air, false, sizeof(air));
		airCheck(0,0);
		
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				meltPointCheck(i, j);
		
		if(!meltCheese()) break;
		ans++;
	}
	cout << ans;
}
