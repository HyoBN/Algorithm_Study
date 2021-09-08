#include <iostream>
using namespace std;
 
char base[3][6] =
{ "  *  ",
  " * * ",
  "*****" };

char map[4000][8000];
 
void star(int n, int y, int x) 
{
	if (n==1){
		for (int i=0;i<3;i++)
			for (int j=0;j<5;j++)
				map[y+i][x+j]=base[i][j];
		return;
	}
 
	star(n/2,y,x+3*n/2);
	star(n/2,y+3*n/2,x);
	star(n/2,y+3*n/2,x+3*n);
 
	return;
}
 
int main()
{
	int n;
	cin >> n;

	for (int i=0;i<n;i++)
		for (int j=0;j<n*2;j++)
			map[i][j] = ' ';

	star(n/3,0,0);

	for (int i=0;i<n;i++) {
		for (int j=0;j<n*2;j++)
			cout << map[i][j];
		cout << '\n';
	}
	return 0;
}