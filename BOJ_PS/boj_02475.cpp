#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int s=0;
	for(int i=0;i<5;i++){
		int tmp;
		cin>>tmp;
		s+=pow(tmp,2);
	}
	cout<<s%10;
}