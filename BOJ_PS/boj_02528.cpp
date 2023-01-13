#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, l, time = 0,y = 0;
	vector<pair<int, int>> p;
	int dir[3001];

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int len, d;
		cin >> len >> d;
		if (d == 0) {
			p.push_back({ 0,len });
			dir[i] = 1;
		}
		else if (d == 1) {
			p.push_back({ l - len,l });
			dir[i] = -1;
		}
	}

	while (true) {
		for (int i = y + 1; i < n; i++) {
			if (p[y].first > p[i].second || p[y].second < p[i].first)
				break;
			else y++;
		}
		if (y == n - 1) break;

		for (int i = 0; i < n; i++) {
			if (p[i].first == 0 && p[i].second == l)
				continue;

			else if ((dir[i] == 1 && p[i].second == 1) || (dir[i] == -1 && p[i].first == 0))
				dir[i] *= -1;
			p[i].first += dir[i], p[i].second += dir[i];		
		}
		time++;
	}
	cout << time;
}
