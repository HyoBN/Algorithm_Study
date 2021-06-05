#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,b;
	vector<int> v;
	
	cin>>n>>b;
	
	while(true)
	{
		v.push_back(n%b);
		n/=b;
		if(n==0) break;
	}
	
	for(int i=v.size()-1;i>=0;i--){
		if(v[i]>=10)
			cout<<(char)(v[i]-10+65);
		else
			cout<<v[i];
	}
}