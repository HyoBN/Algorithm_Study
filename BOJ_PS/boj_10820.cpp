#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	int n;
	int ans[4]={0,};
	string str;
	
	//아스키코드. 소문자 97~122, 대문자 65~90, 공백 : 32
	
	for(int i=0;i<100;i++)
	{
		getline(cin,str);
		if(str.length()==0) // EOF 입력될때까지 받는 것과 동일.
			break;
		for(int j=0;j<str.size();j++){
			if((int)str[j]>=97 &&(int)str[j]<=122)
				ans[0]++;
			else if((int)str[j]>=65 && (int)str[j]<=90)
				ans[1]++;
			else if((int)str[j]==32)
				ans[3]++;
			else ans[2]++;
		}
		for(int k=0;k<4;k++)
			cout<<ans[k]<<" ";
		cout<<endl;
		memset(ans,0,sizeof(ans));
	}
}