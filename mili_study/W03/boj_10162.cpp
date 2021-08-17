#include <iostream>
int main()
{
	int t;
	scanf("%d",&t);
	t%10!=0 ? printf("-1") : printf("%d %d %d",t/300, (t%300)/60,(t%60)/10);
}