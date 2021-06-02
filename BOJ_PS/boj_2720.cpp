#include <iostream>
using namespace std;

int main()
{
	int t;
	
	cin>>t;
	
	for(int i=0;i<t;i++){
		int money[4]={0,};
		int c;
		cin>>c;
		while(c>=25)
		{
			c-=25;
			money[0]++;
		}
		while(c>=10)
		{
			c-=10;
			money[1]++;
		}
		while(c>=5)
		{
			c-=5;
			money[2]++;
		}
		while(c>=1)
		{
			c-=1;
			money[3]++;
		}
		
		for(int j=0;j<4;j++)
			cout<<money[j]<<" ";
		cout<<endl;
		
	}
}