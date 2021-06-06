#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string result;
	
	if(n==0)
		cout<<0;
    while (n != 0)
    {
        if (n % -2 == 0)
        {
            result += "0";
            n /= -2;
        }
        else
        {
            result += "1";
            n = (n - 1) / -2;
        }
    }
	for(int i=result.size()-1;i>=0;i--)
		cout<<result[i];
}