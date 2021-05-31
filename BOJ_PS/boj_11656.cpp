#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	cin>>str;
	
	string arr[1001];
	for(int i=0;i<str.size();i++)
	{
		string piece;
		for(int j=i;j<str.size();j++)
			piece+=str[j];
		arr[i]=piece;
	}
	sort(arr,arr+str.size());
	
	for(int i=0;i<str.size();i++)
		cout<<arr[i]<<endl;
	return 0;
}