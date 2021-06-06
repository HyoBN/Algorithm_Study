#include <iostream>
using namespace std;

int main()
	
{
	int x;
	int num=64;
	int count =0;
	cin>>x;
	
	while(x!=0)
	{
		if(x>=num)
		{
			x-=num;
			count++;
		}
		num/=2;
	}
	
	cout<<count;
}