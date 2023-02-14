#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
};
int xLen, yLen;
int N;
point pos[500002];
long long sum, ans_cnt, ans_max;

bool is_Xborder(point p1, point p2) {
	return (p1.x == p2.x && (p1.x == 0 || p1.x == xLen));
}

bool is_Yborder(point p1, point p2) {
	return (p1.y == p2.y && (p1.y == 0 || p1.y == yLen));
}

long long dist(point p1, point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

long long length(int start, int end) {
	point p1 = pos[start];
	point p2 = pos[end];
	long long sum = 0;
	while (true) {
		if (is_Yborder(p1, p2) || is_Xborder(p1, p2)) {
			return sum += dist(p1, p2);
		}
		if (p1.y == 0 && p1.x != xLen) {
			sum += (xLen - p1.x);
			p1.x = xLen;
		}
		else if (p1.x == 0 && p1.y != 0) {
			sum += p1.y;
			p1.y = 0;
		}
		else if (p1.x != 0 && p1.y == yLen) {
			sum += p1.x;
			p1.x = 0;
		}
		else if (p1.x == xLen && p1.y != yLen) {
			sum += (yLen - p1.y);
			p1.y = yLen;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> xLen >> yLen;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos[i].x >> pos[i].y;
	}
	pos[N].x = pos[0].x;
	pos[N].y = pos[0].y;
	int s = 1, e;
	bool chk = 0;
	for (int i = 0; i < N; i++) {
		if (is_Xborder(pos[i], pos[i + 1]) || is_Yborder(pos[i], pos[i + 1])) {
			chk = 1;
			s = (i + 1) % N;
			break;
		}
	}
	if (chk == 0) {
		ans_cnt = 1;
		ans_max = xLen * 2 + yLen * 2;
		for (int i = 0; i < N; i++) {
			ans_max += dist(pos[i], pos[i + 1]);
		}
		cout << ans_cnt << " " << ans_max;
		return 0;
	}
	
	e = s;
	for (int i = 0; i < N; i++) {
		if (is_Xborder(pos[e], pos[e + 1]) || is_Yborder(pos[e], pos[e + 1])) {
			if (!chk) {
				ans_cnt++;
				sum += length(s, e);
				ans_max = max(ans_max, sum);
				sum = 0;
				chk = 1;
			}
			s = (e + 1) % N;
		}
		else {
			chk = 0;
			sum += dist(pos[e], pos[e + 1]);
		}
		e = (e + 1) % N;
	}
	cout << ans_cnt << " " << ans_max;
}
