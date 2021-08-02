#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int cnt=1;
	
	if(s[0]==' ' && s.size()==1) cnt--;

	for(int i=1;i<s.size()-1;i++)
		if(s[i]==' ')
			cnt++;
	
	cout<<cnt;
}