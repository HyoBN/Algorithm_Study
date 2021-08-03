#include <iostream>
using namespace std;

int main()
{
	int arr[101][101]={0,};
	int a,b,c,d;
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		cin>>a>>b>>c>>d;
		for(int j=b;j<d;j++)
			for(int k=a;k<c;k++)
				arr[j][k]=1;
		
	}
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			if(arr[i][j]==1) cnt++;
	
	cout<<cnt;
}