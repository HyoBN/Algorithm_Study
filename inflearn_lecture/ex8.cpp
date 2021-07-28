// 문제 8번. 올바른 괄호.
// 괄호 쌍이 알맞게 짝지어지면 YES, 아니면 NO 출력.
// ex.  input : (()(()
//		output : NO

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count=0;
	string s;
	
	cin>>s;
	
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='(') count++;
		else if(s[i]==')') count--;
		
		if(count<0)
			break;
		
	}
	cout<<(count==0 ? "YES" : "NO");
}