#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int t,x,y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		double root=sqrt(y-x);
		int root_int=round(root);
		cout<<(root>root_int ? root_int*2 : root_int*2-1)<<endl;
	}
}