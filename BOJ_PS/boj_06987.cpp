#include <iostream>
#include <vector>
using namespace std;

int a[6][3];
vector<pair<int, int>> g;

bool back(int n) {
	if (n == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[i][j])
					return false;
			}
		}
		return true;
	}
	pair<int, int> tmp = g[n];
	if (a[tmp.first][1] && a[tmp.second][1]) {
		a[tmp.first][1]--, a[tmp.second][1]--;
		if (back(n + 1)) return true;
		a[tmp.first][1]++, a[tmp.second][1]++;
	}
	if (a[tmp.first][0] && a[tmp.second][2]) {
		a[tmp.first][0]--, a[tmp.second][2]--;
		if (back(n + 1)) return true;
		a[tmp.first][0]++, a[tmp.second][2]++;
	}
	if (a[tmp.first][2] && a[tmp.second][0]) {
		a[tmp.first][2]--, a[tmp.second][0]--;
		if (back(n + 1)) return true;
		a[tmp.first][2]++, a[tmp.second][0]++;
	}
	return false;

}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j <= 5; j++) {
			g.push_back({ i,j });
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for(int k=0;k<3;k++)
				cin >> a[j][k];
		}
		cout << back(0)<<" ";
	}
}
