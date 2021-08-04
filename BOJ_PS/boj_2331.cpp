#include <iostream>
#include <cmath>
#include <cstring>

#define MAX 236197
using namespace std;

int p;
int visited[MAX];

void D(int num){
	if (visited[num]++ == 3)
		return;
	int sum = 0;
	while (num)
	{
		 sum += (int)pow((num % 10), p);
		 num /= 10;
	}
	D(sum);
}
 
int main(void)
{
	int a;
	scanf("%d %d",&a,&p);
	D(a);
	int res = 0;
	for (int i=0; i<MAX; i++)
		 if (visited[i] == 1)
				 res++;
	printf("%d",res);
}