#include <iostream>
using namespace std;

int main()
{
	int n,sum = 0;
	char ch;
	scanf("%d ",&n); //입력받을 때 %d 뒤에 공백 한 칸 넣어서 다음 scanf와 구분 해줘야 함.
	
	for (int i = 0; i < n; i++)
	{
		scanf("%c",&ch);
		sum += ch - 48; //아스키코드 
	}
	printf("%d",sum);
	return 0;
}