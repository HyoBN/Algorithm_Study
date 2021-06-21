#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

int main()
{
	int n;
	int arr[500001];
	int count[8001]={0,};
	int freq=0;
	int location=0;
	
	int sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		count[arr[i]+4000]++;
		sum+=arr[i];
	}
	sort(arr,arr+n);
	
	for(int i=0;i<8001;i++)
	{
		if(freq<count[i]){
			freq=count[i];
			location=i;
		}
	}
	for(int i=location+1;i<8001;i++)
	{
		if(freq==count[i])
		{
			location=i;
			break;
		}
	}
	
	cout<<round((float)sum/n)<<endl; //산술 평균
	cout<<arr[n/2]<<endl; //중앙값
	cout<<location-4000<<endl; //최빈값
	cout<<arr[n-1]-arr[0]<<endl; //범위
}
