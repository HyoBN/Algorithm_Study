#include <iostream>
using namespace std;

int main(){
	int cnt,tmp;
	int idx,max=1;
	int arr[6];
	cin>>cnt;
	
	for(int i=0;i<6;i++)
		cin>>tmp>>arr[i];
	
	for(int i=0;i<6;i++){
		int mul=arr[i]*arr[(i+1)%6];
		if(max<mul){
			max=mul;
			idx=i;
		}
	}
	int small=arr[(idx+3)%6]*arr[(idx+4)%6];
	cout<<(max-small)*cnt;
}