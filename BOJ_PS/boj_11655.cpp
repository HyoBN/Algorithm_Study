#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	//아스키코드 소문자 : 97~122 대문자 : 65~90
	//아스키코드가 127번까지만 정의되어 있기 때문에 13을 더했을때 127을 초과하게 되는 경우 출력이 되지않는다. 이는 값을 호출하지 않더라도 string 형 변수에 저장 자체가 제대로 되지 않는다.
	for(int i=0;i<str.size();i++)
	{
		if((int)str[i]>=65 &&(int)str[i]<=77) // 대문자
			str[i]=(int)str[i]+13;
		else if((int)str[i]>=78 &&(int)str[i]<=90) // 대문자
			str[i]=(int)str[i]-13;
		
		else if((int)str[i]>=97 &&(int)str[i]<=109) // 소문자
			str[i]=(int)str[i]+13;
		else if((int)str[i]>=110 &&(int)str[i]<=122) // 소문자
			str[i]=(int)str[i]-13;	
	}
	cout<<str;
	
}