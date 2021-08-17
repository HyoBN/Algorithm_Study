#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	
	if(t%10!=0) printf("-1");
	else{
		t/=10;
		printf("%d %d %d",t/30,(t%30)/6,t%6);
	}
}