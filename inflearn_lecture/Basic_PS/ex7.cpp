// 문제 7번. 알파벳과 공백만으로 이루어진 입력을 받아 공백제거, 소문자화하여 출력.
// ex) input : bE  au T I  fu  L
//     output : beautiful

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
			continue;
		else if(s[i]<97)
			cout<<char(s[i]+32);
		else
			cout<<s[i];
	}	
}