#include <iostream>
#include <string>
using namespace std;

int main()
{
	int b;
	string str;
	long long sum=0;
	cin>>str>>b;
	int cur=1;
	
	for(int i=str.size()-1;i>=0;i--){
		if(str[i] >='A')
			sum+=(str[i]-'A'+10)*cur;
		else
			sum+=(str[i]-'0')*cur;
		cur*=b;
	}
	cout<<sum;

}
