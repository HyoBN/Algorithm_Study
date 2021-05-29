#include <iostream>
#include <string>
using namespace std;

int main()
{
	int stick_cnt=0;
	int piece=0;
	string str;
	getline(cin,str);
	
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(' && str[i+1]==')'){
			piece+=stick_cnt;
			i++; //'()' 하나가 한쌍으로 레이저 위치나타내므로 ')' 건너뛰어야함.
		}
		else if(str[i]=='(' && str[i+1]!=')') // 쇠막대기 하나 추가.
			stick_cnt++;
		else if(str[i]==')'){ //한 쇠막대기의 끝.
			stick_cnt--;
			piece++; // 쇠막대기 하나 자르면 두 piece가 되는 것을 처리.
		}
	}
	cout<<piece;
		
	return 0;
}