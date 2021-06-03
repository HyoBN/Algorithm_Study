#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string str[10];
	int str_size=0;
	int alpha[26]={0,};
	int num=9;
	int result=0;
	
	for(int i=0;i<n;i++){
		cin>>str[i];
		str_size++;
	}
	
	for(int i=0;i<str_size;i++) //문자열 개수만큼 반복.
	{
		int pow=1; //string을 숫자로 바꾸어 덧셈처리하기 위한 변수.
		for(int j=str[i].size()-1;j>=0;j--)
		{
			int alphabet=str[i][j]-'A'; //몇 번째 알파벳인지 저장.
			alpha[alphabet]+=pow;
			pow*=10;
		}
		//각 알파벳별로 1을넣고 나머지 알파벳을 0이라 했을때, 나오는 계산결과값을 alpha 배열에 저장.
	}
	
	sort(alpha,alpha+26);
	for(int i=25;i>=0;i--){
		if(alpha[i]==0) break;
		result+=(alpha[i]*num);
		num--;
	}
	
	cout<<result;
}
	