#include <iostream>
using namespace std;

int main()
{
	int k,n,answer=0;
	int arr[10001];
	int maxi=0;
	long long mid,high,low=1;
	
	cin>>k>>n;
	for(int i=0;i<k;i++)
	{
		cin>>arr[i];
		if(maxi<arr[i]) maxi=arr[i];
	}
	high=maxi;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		int cnt=0;
		for(int i=0;i<k;i++)
			cnt+=arr[i]/mid;
		if(cnt>=n)
		{
			low=mid+1;
			if(answer<mid) answer=mid;
		}
		else
			high=mid-1;
	}
	cout<<answer;
	
}