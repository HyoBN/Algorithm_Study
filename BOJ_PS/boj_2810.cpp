#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int count =0;
	int flag=1;
	cin>>n;
	string str;
	
	cin>>str;
	
	for(int i=0;i<n;i++)
	{
		if(str[i]=='L' && str[i+1]=='L')
		{
			flag=0;
			count++;
			i++;
		}
	}
	if(flag) n--; //LL이 하나도 없는 경우.
	cout<<n-count+1;
}
