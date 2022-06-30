#include <iostream>
using namespace std;

int main(){
	int t,n,m;
	int a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		while(m--)
			cin>>a>>b;
		cout<<n-1<<'\n';
	}
	return 0;
}
