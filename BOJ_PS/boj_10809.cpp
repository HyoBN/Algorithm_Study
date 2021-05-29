#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int alphabet[26];
	memset(alphabet,-1, 26*sizeof(int));
	string str;
	cin>>str;
	
	for(int i=str.size()-1;i>=0;i--)
		alphabet[(int)str[i]-97]=i;
	for(int i=0;i<26;i++)
		cout<<alphabet[i]<<" ";
	return 0;
}