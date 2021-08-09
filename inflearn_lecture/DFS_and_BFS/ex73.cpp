// 문제 73. 자연수를 입력받다가 0이 입력되면 최댓값(최솟값)을 꺼내어 출력, 자료가 없으면 -1 출력. -1이 입력되면 종료.
// 최댓값 -> 최대힙 / 최솟값 -> 최소힙
// 최소힙 - 자연수를 입력받아 -1을 곱하여 priority_queue에 넣어 정렬한 후, -1을 곱하여 최솟값 출력.

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
				printf("%d\n",pq.top()); // 최대힙.
				printf("%d\n",(-1)*pq.top()); // 최소힙.
				pq.pop();
			}
		}
		else pq.push(a); //최대힙.
		//else pq.push((-1)*a); 최소힙.
	}
}