#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int arr[4][8];
int isRotate[4];

void cw(int gear) {
	int tmp = arr[gear][7];
	for (int i = 7; i > 0; i--)
		arr[gear][i] = arr[gear][i - 1];
	arr[gear][0] = tmp;
}

void ccw(int gear) {
	int tmp = arr[gear][0];
	for (int i = 0; i < 7; i++)
		arr[gear][i] = arr[gear][i + 1];
	arr[gear][7] = tmp;
}

void rotate(int gear, int clock) {
	if (clock == 1)
		cw(gear);
	else if (clock == -1)
		ccw(gear);
}

void left(int gear, int clock) {
	if (gear <= 0) return;
	if (arr[gear][6] != arr[gear - 1][2]) {
		isRotate[gear - 1] = clock * -1;
		left(gear - 1, clock * -1);
	}
}

void right(int gear, int clock) {
	if (gear >= 3) return;
	if (arr[gear][2] != arr[gear + 1][6]) {
		isRotate[gear + 1] = clock * -1;
		right(gear + 1, clock * -1);
	}
}

void check(int gear, int clock) {
	isRotate[gear] = clock;
	left(gear, clock);
	right(gear, clock);
	for (int i = 0; i < 4; i++)
		rotate(i, isRotate[i]);
}

int main() {
	int k,ans=0;
	int which, clock;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	cin >> k;
	while (k--) {
		cin >> which >> clock;
		memset(isRotate, 0, sizeof(isRotate));
		check(which - 1, clock);
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1)
			ans += pow(2, i);
	}
	cout << ans;
}
