// 문제 73. 자연수를 입력받다가 0이 입력되면 최댓값을 꺼내어 출력, 자료가 없으면 -1 출력. -1이 입력되면 종료.

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int a;
	priority_queue<int> pq;
	while(true){
		scanf("%d",&a);
		if(a==-1) break;
		if(a==0)
		{
			if(pq.empty()) printf("-1\n");
			else{
				printf("%d\n",pq.top());
				pq.pop();
			}
		}
		else pq.push(a);
	}
}5