#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,w,h,tmp;
	cin>>n>>w>>h;
	while(n--){
		cin>>tmp;
		cout<<(tmp <= sqrt(pow(w,2)+pow(h,2)) ? "DA":"NE")<<endl;
	}
}