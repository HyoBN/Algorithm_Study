#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	int a,b,t;
	int n;
	long long arr[100];
	long long sum=0;
	cin>>t;
	for(int i=0;i<t;i++){
		sum=0;
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>arr[j];
		
		for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
				sum+=gcd(arr[x],arr[y]);
			
		}
		cout<<sum<<endl;
		
	}
	
	
}