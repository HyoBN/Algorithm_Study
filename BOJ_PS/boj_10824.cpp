#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	long long x,y;
	a+=b;
	c+=d;
	x=stoll(a); //stoi를 사용하게 되면 a가 int형 범위를 벗어나게 되면 에러남! 
	y=stoll(c);
	
	cout<<x+y;
	return 0;
	
}