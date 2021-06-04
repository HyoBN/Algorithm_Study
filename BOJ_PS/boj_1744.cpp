#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int arr[10001];
	int sum=0;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	sort(arr,arr+n);
	
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]==1 || i==0)
			sum+=arr[i];
		
		else if(arr[i]>0 && arr[i-1]==1){// 양수와 1이 있는 경우 둘을 곱하는거보다 둘 다 더하는게 1 더 큼.
			sum+=arr[i]+arr[i-1];
			i--;
		}
		
		else if(arr[i]>0 && arr[i-1]<=0)
			sum+=arr[i];
		
		else if(arr[i]==0 && arr[i-1]<0)
		{
			if(i%2==0) //음수가 짝수개 남은 경우
				continue;
			else // 음수가 홀수개 남은 경우.
				i--; //어짜피 0이라 곱할거니까 패스해도됨.
		}
		
		else if(arr[i]<0)
		{
			if(i%2==0){
				sum+=arr[i];
				continue;
			}
			else // 음수가 홀수개 남은 경우.
			{
				sum+=arr[i]*arr[i-1];
				i--; //어짜피 0이라 곱할거니까 패스해도됨.
			}
		}
		
		else {
			sum+=arr[i]*arr[i-1];
			i--;
		}
	}
	cout<<sum;
	
}


