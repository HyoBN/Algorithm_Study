#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	int map[701][701];
	vector<int> growth;
	
	int m,n,x;
	
	scanf("%d %d",&m,&n);
	vector<int> total_growth(2*m-1);

	for(int i=0;i<n;i++) //date
	{
		for(int j=0;j<3;j++) // 성장 정도(0,1,2)
		{
			scanf("%d",&x);
			for(int k=0;k<x;k++) //0,1,2 각각의 개수만큼 반복
				growth.push_back(j); // input : 1 2 3 -> growth={0,1,1,2,2,2}
		}
		for(int j=0;j<growth.size();j++)
			total_growth[j]+=growth[j];

		growth.clear();
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(j==0)
				printf("%d ",total_growth[m-i-1]+1);
			else
				printf("%d ",total_growth[j+m-1]+1);
		}
		printf("\n");
	}
}