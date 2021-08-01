// 문제 19. 한 줄에 앉는 학생 수를 입력받은 후 학생 들의 키를 앞자리에 앉은 학생부터 입력받는다.
//			뒷 자리에 있는 모든 학생들 보다 키가 큰 경우 분노유발자라 칭한다. 총 분노 유발자가 몇명인지 출력하는 프로그램이다.
// ex. input : 10 \n 56 46 55 76 65 53 52 53 55 50
//     output : 3
//		76,65,55가 분노 유발자 이다.


//처음 짰던 코드

#include <iostream>
using namespace std;

int main()
{
	int n,cnt=0,flag;
	int arr[101];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	for(int i=0;i<n-1;i++)
	{
		flag=0;
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				flag=1;
				break;
			}
			
			
		}
		if(flag==0) cnt++;
	}
	printf("%d",cnt);
}


// 보완 코드.

#include <iostream>
using namespace std;

int main()
{
	int n,cnt=0,max;
	int arr[101];
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	
	max=arr[n];
	for(int i=n-1;i>=1;i--)
	{
		if(arr[i]>max){
			max=arr[i];
			cnt++;
		}
	}
	printf("%d",cnt);
}