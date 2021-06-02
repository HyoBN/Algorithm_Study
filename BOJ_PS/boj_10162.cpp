#include <iostream>
using namespace std;

int main()
{
	int t;
	int count[3]={0,};
	cin>>t;
	
	while(t>=300)
	{
		t-=300;
		count[0]++;
	}
	while(t>=60)
	{
		t-=60;
		count[1]++;
	}
	while(t>=10)
	{
		t-=10;
		count[2]++;
	}
	
	if(t!=0) cout<<-1;
	
	else{
		for(int i=0;i<3;i++)
			cout<<count[i]<<" ";
	}


	
}