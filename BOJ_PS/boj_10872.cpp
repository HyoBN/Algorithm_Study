#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int result=1;
	if(n==0)
		cout<<1;
	
	else
	{
		while(n>0)
		{
			result*=n;
			n--;
		}
		cout<<result;
	}
	
}