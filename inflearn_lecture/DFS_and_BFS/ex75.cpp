// 문제 75. n개의 기업에서 강연 요청을 하였는데, 각 기업은 D일 안에 와서 강연을  해주면 M만큼의 강연료를 준다고 한다.
// 각 기업이 요청한 D,M을 바탕으로 가장 많은 돈을 벌 수 있는 강연 스케쥴을 짜라. 하루에 하나의 강연만 가능하다.

// ex. input :
// 6
// 50 2
// 20 1
// 40 2
// 60 3
// 30 3
// 30 1
// ouput : 150

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Data{
	int money;
	int when;
	Data(int a, int b)
	{
		money=a;
		when=b;
	}
	bool operator<(Data &b){
		return when>b.when; //날짜 내림차순으로 정렬.
	}
};

int main()
{
	int n,a,b,res=0,max=-21470000000;
	int j=0;
	vector<Data> t;
	priority_queue<int> pq;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		t.push_back(Data(a,b));
		if(b>max)
			max=b;
	}
	sort(t.begin(), t.end());
	
	for(int i=max;i>=1;i--)
	{
		for(;j<n;j++) //한 번 비교한 데이터는 건너뛰기 위해 j=0을 쓰지 않고 바깥 for문의 바깥에서 j=0 초기화.
		{
			if(t[j].when<i) break; //지정 기간 내 데이터들만 비교하기 위해.
			pq.push(t[j].money);
		}
		if(!pq.empty())
		{
			res+=pq.top(); // 해당 기간 중 최댓값 하나만 더함.
			pq.pop(); // 하나만 뺐으므로 나머지는 pq에 남아있음. -> 나머지는 (i--)한 기간 내 데이터들과 같이 비교.
		}
	}
	
	printf("%d",res);
}