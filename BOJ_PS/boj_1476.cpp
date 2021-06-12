#include <iostream>
using namespace std;

int main()
{
	int e,s,m;
	int a=1,b=1,c=1;
	int count=1;
	cin>>e>>s>>m;
	
	while(true)
	{
		if(a==e && b==s && c==m)
			break;
		
		if(a==15)
			a=0;
		if(b==28)
			b=0;
		if(c==19)
			c=0;
		a++;
		b++;
		c++;
		count++;
	}
	cout<<count;
	
}