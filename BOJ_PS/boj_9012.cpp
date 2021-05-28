#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	
	int num=0;
	char ch[51];
	string str;
	cin>>t;
	cin.ignore(); //cin 버퍼를 비우는 역할.
	for(int i=0;i<t;i++){
		num=0;
		getline(cin,str);
		
		for(int j=0;j<str.size();j++)
		{
			if(str[j]=='(') num++;
			else if(str[j]==')') num--;
			if(num<0){
				cout<<"NO"<<endl;
				break;
			}
		}
		if(num==0) cout<<"YES"<<endl;
		else if(num>0) cout<<"NO"<<endl;
		
	}
	return 0;
}