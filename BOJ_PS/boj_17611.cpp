#include <iostream>
#include <cmath>
using namespace std;

int xAmount[2000001];
int yAmount[2000001];

void yCounting(int y1, int y2) {
	for (int j = min(y1, y2) + 1; j < max(y1, y2); j++)
		yAmount[j]++;
}

void xCounting(int x1, int x2) {
	for (int j = min(x1, x2) + 1; j < max(x1, x2); j++)
		xAmount[j]++;
}
int main() {
	int n;
	int x0, y0;
	int xTmp, yTmp;
	int x, y;
	int ans = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x *= 2, y *= 2;
		x += 1000000;
		y += 1000000;
		if (i == 0) {
			x0 = x, xTmp = x;
			y0 = y, yTmp = y;
			continue;
		}
		if (xTmp == x)
			yCounting(yTmp, y);
		
		else if (yTmp == y)
			xCounting(xTmp, x);
		
		xTmp = x, yTmp = y;
	}

	if (xTmp == x0)
		yCounting(yTmp, y0);
	
	else if (yTmp == y0)
		xCounting(xTmp, x0);

	for (int i = 1; i < 2000001; i++)
		ans = max(ans, max(xAmount[i], yAmount[i]));
	
	cout << ans;
}
