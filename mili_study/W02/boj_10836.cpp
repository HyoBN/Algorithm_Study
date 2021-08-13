#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	int map[701][701];
	vector<int> growth;
	int m,n,x;
	int index;
	
	scanf("%d %d",&m,&n);

	for(int i=0;i<n;i++) //date
	{
		for(int j=0;j<3;j++) // 성장 정도(0,1,2)
		{
			scanf("%d",&x);
			for(int k=0;k<x;k++) //0,1,2 각각의 개수만큼 반복
				growth.push_back(j); // input : 1 2 3 -> growth={0,1,1,2,2,2}
		}
		
		index=0;
		for(int k=m-1;k>=0;k--) // 0번째 열(m-1행부터)
			map[k][0]+=growth[index++];
		
		for(int k=1;k<m;k++) //0번째 행(1열부터)
			map[0][k]+=growth[index++];
	
		index=m; // (1,1) ~ (m-1,m-1)는 (0,1) ~ (0,m-1)값에 종속적이므로 growth 벡터의 m~끝까지 인덱스만 접근하면 됨.
		
        for(int p=1;p<m;p++){
			for(int k=1;k<m;k++)
				map[p][k]+=growth[index++];
			index=m;
		}
		
		growth.clear();
	}
	
	for(int i=0;i<m;i++){
			for(int j=0;j<m;j++)
				printf("%d ",map[i][j]+1); // 배열:0으로 초기화, 시작값:1
			printf("\n");
	}
}