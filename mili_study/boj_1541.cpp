#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	string tmp="";
	int answer=0;
	bool check=false;
	
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='+' || s[i]=='-' ||s[i]=='\0')
		{
			if(check)
				answer-=stoi(tmp);
			else
				answer+=stoi(tmp);
			if(s[i]=='-')
				check=1;
			tmp="";
			continue;
		}
		tmp+=s[i];
				
	}
	cout<<answer;
}