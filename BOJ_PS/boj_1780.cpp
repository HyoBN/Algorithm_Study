#include <iostream>
using namespace std;

int answer[3];
int map[2200][2200];

bool check(int y, int x, int num) {
	int start = map[y][x];
	
	for (int i=y;i<y+num;i++) {
		for (int j=x;j<x+num;j++) {
			if (start != map[i][j])
				return false;
		}
	}
	return true;
}

void divide(int y, int x, int num) {
	if (check(y,x,num)) 
		answer[map[y][x]]++;
	else
	{
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				divide(y+(num/3)*i, x+(num/3)*j,(num/3));
			
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			int input;
			scanf("%d", &input);
			input++;
			map[i][j] = input;
		}
	}
	divide(0, 0, N);
	for(int i=0;i<3;i++)
		printf("%d\n",answer[i]);

}