#include <iostream>
#include <string>
using namespace std;

int main()
{
	string eight[8]={"000","001","010","011","100","101","110","111"};
	string str;
	
	cin>>str;
	
	cout<<stoi(eight[str[0]-'0']);
	for(int i=1;i<str.size();i++)
		cout<<eight[str[i]-'0'];

}