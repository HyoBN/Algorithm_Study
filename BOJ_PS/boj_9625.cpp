#include <iostream>
using namespace std;

int main()
{
	int k;
	cin>>k;
	
	int a[46]={0,1,};
	int b[46]={1,1,};
	
	for(int i=2;i<k;i++)
	{
		a[i]=a[i-2]+a[i-1];
		b[i]=b[i-2]+b[i-1];
	}
	cout<< a[k-1]<<" "<<b[k-1];
	
}