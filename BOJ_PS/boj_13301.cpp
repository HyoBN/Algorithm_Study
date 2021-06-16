#include <iostream>
using namespace std;

int main()
{
	int n;
	long long arr[83]={0,0,1,1,};
	cin>>n;
	
	for(int i=4;i<n+2;i++)
		arr[i]=arr[i-1]+arr[i-2];
	
	cout<<arr[n+1]*4+arr[n]*2;
}