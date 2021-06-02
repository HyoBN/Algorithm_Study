#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str;
	cin>>str;
	string number="";
	int num=0;
	int check=0;
	for(int i=0;i<=str.size();i++)
	{
		if(str[i]=='+' || str[i]=='-' || str[i]=='\0')
		{
			if(check)
				num-=stoi(number);
			else
				num+=stoi(number);
			if(str[i]=='-')
				check=1;
			number="";
			continue;
		}
		number+=str[i];
				
	}
	cout<<num;
}

