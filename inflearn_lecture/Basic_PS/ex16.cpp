// 문제 16. 입력받은 두 문자열이 구성이 일치하면 YES출력, 다르면 NO 출력.
// ex. input : AbaAeCe \n baeeACA
//	   output : YES

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char a[101];
	char b[101];
	
	int c[60]={0,};
	int d[60]={0,};
	bool flag=true;
	scanf("%s",&a);
	scanf("%s",&b);
	
	
	for(int i=0;a[i]!='\0';i++)
		c[a[i]-65]++;
	
	for(int i=0;b[i]!='\0';i++)
		d[b[i]-65]++;
	
	for(int i=0;i<60;i++)
	{
		if(c[i]!=d[i]){
			printf("NO");
			flag=false;
			break;
		}
	}
	if(flag==true) printf("YES");
}