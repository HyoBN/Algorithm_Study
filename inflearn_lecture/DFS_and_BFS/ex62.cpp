//문제 62. N개의 숫자를 오름차순으로 병합정렬하여 출력하라.

#include <iostream>
using namespace std;

int data[10], tmp[10];

void divide(int start, int end)
{
	int mid;
	int p1, p2, p3;
	if(start<end)
	{
		mid=(start+end)/2;
		divide(start, mid);
		divide(mid+1, end);
		p1=start;
		p2=mid+1;
		p3=start;
		while(p1<=mid && p2<=end)
		{
			if(data[p1]<data[p2]) tmp[p3++]=data[p1++];
			else tmp[p3++]=data[p2++];
		}
		while(p1<=mid) tmp[p3++] = data[p1++];
		while(p2<=end) tmp[p3++] = data[p2++];
		for(int i=start;i<=end;i++)
			data[i]=tmp[i];
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	divide(1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",data[i]);
	
	
}