#include<iostream>
#include<stack>
using namespace std;


int main()
{
	int n;
	int ans[1000001];
	int arr[1000001];
	stack<int> s;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && s.top()<=arr[i])
			s.pop();

		ans[i] = (s.empty() ? -1 : s.top());
		s.push(arr[i]);
	}
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
}