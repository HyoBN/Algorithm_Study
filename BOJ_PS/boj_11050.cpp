#include <iostream>
using namespace std;

int main()
{
	int n,k;
	int combi[11]={1,1,};
	cin>>n>>k;
	
	for(int i=2;i<=n;i++)
		combi[i]=combi[i-1]*i;
	
	cout<<combi[n]/(combi[k]*combi[n-k]);
}