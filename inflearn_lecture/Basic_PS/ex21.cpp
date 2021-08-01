// 문제 21. 0~9의 숫자 카드를 가지고 A와 B가 게임을 한다.
// 두 사람의 카드의 숫자값을 입력 받은 후 각 라운드 마다 이긴 사람이 3점, 비기는 경우에는 모두 1점을 가져간다.
// 총 10라운드의 게임이 끝난 후 A와 B의 점수, 승자를 출력.
// 10라운드의 결과가 모두 비겼을 시 "D"출력, 승점만 같은 경우에는 마지막에 이긴 사람이 승자.
// ex. input : 9 1 7 2 6 3 0 4 8 5
//			   6 3 9 2 1 0 7 4 8 5
//	   output : 13 13 \n B


#include <iostream>
using namespace std;

int main()
{
	int n=10;
	int a[10];
	int b[10];
	int a_score=0, b_score=0;
	int a_index=0,b_index=0;
	
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	
	for(int i=0;i<n;i++)
	{
		if(a[i]>b[i])
		{
			a_score+=3;
			a_index=i;
		}
		else if(a[i]<b[i])
		{
			b_score+=3;
			b_index=i;
		}
		else if(a[i]==b[i]){
			a_score++;
			b_score++;
		}
	}
	printf("\n%d %d\n", a_score, b_score);
	
	if(a_score==b_score)
	{
		if(a_index==b_index) printf("D");
		else
			a_index>b_index ? printf("A") : printf("B");
	}
	else
		a_score>b_score ? printf("A") : printf("B");
	
	
	
	
}