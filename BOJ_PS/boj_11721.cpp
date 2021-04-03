#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str[100];
	scanf("%s",&str);
	for(int i=0;i<strlen(str);i++){
	    if(i!=0 && i%10==0) printf("\n");
	    printf("%c",str[i]);
	
	}
}