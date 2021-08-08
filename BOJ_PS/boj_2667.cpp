#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int arr[25][25];
bool visited[25][25];
vector <int> vec;

int cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void DFS(int x, int y) {
	cnt++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (arr[nx][ny] == 1 && visited[nx][ny] == false){
			DFS(nx, ny);
		}
	}
}

int main() {
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++)
		for(int j=0;j<n;j++)
			scanf("%1d",&arr[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				cnt = 0;
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	printf("%d\n",(int)vec.size());
	
	for (int i = 0; i < vec.size(); i++)
		printf("%d\n",vec[i]);

	return 0;
}
