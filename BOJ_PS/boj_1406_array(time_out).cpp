#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	int m;
	int pointer;
	char command;
	int real_size;
	string piece;
	string push_ch;
	
	cin>>str;
	cin>>m;
	pointer=str.size(); //pointer 위치 초기 설정.
	real_size=str.size(); // size가 바뀔거기때문에 변수 선언해서 초기화.
	for(int i=0;i<m;i++)
	{
		cin>>command;
	
		if(command=='L')
		{
			if(pointer!=0)
				pointer--;
		}
		
		else if(command=='D')
		{
			if(pointer!=real_size)
				pointer++;
		}
		
		//커서의 위치와 str.size() 연산을 통해 커서 오른쪽 문자열을 전부 piece에 저장해놓음.
		//그걸 한 칸 왼쪽에 갖다붙임.
		
		else if(command=='B')
		{
			if(pointer==0)
				continue;
			else{
				piece=""; //맨 오른쪽에 있을 경우 고려.
				for(int j=pointer;j<real_size;j++)
					piece+=str[j];
				pointer--;
				for(int k=pointer;k<real_size;k++)
					str[k]=piece[k-pointer];
				real_size--;
				
			}
		}
		
		else if(command=='P'){
			piece="";
			
			cin>>push_ch;
			for(int j=pointer;j<real_size;j++)
				push_ch+=str[j]; //입력받은 문자뒤에 기존 문자붙임.
			real_size++;
			for(int k=pointer;k<real_size;k++)
				str[k]=push_ch[k-pointer];
			pointer++;
		}
		
	}
	for(int i=0;i<real_size;i++)
		cout<<str[i];
		
	return 0;
}


// for문을 사용하면 최악의 경우 문자열 길이만큼 다 탐색을 해야하기 때문에 시간복잡도 O(N)을 가진다.
// 따라서 문제 조건 시간을 초과하여 시간 초과 에러가 발생하게 된다.
// 애초에 배열만을 사용하여 문제 조건을 만족시키기 위해서는 필연적으로 for문을 사용해야 하기때문에 
// 문제 조건 시간을 초과하게 된다. stack, list 등의 다른 자료형을 활용하는 것이 훨씬 간단할 것이다.

