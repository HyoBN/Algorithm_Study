//여러 개의 변수를 사용하거나 묶어야 하는 경우, 구조체를 사용하면 효율적일 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Loc{ //구조체 선언.
	int x,y,z; 
	Loc(int a, int b, int c) // 생성자.
	{
		x=a;
		y=b;
		z=c;
	}
	
	bool operator<(const Loc &b)const{ //연산자 오버로딩.
		// x값이 같으면 y, y값이 같으면 z값 순서로 비교.
		
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		if(z!=b.z) return z<b.z;
	}
};

int main()
{
	vector<Loc> xy;
	xy.push_back(Loc(2,3,5));
	xy.push_back(Loc(3,6,7));
	xy.push_back(Loc(2,3,1));
	xy.push_back(Loc(5,2,3));
	xy.push_back(Loc(3,1,6));
	sort(xy.begin(),xy.end()); //sort과정 중, 위 구조체에서 오버로딩한 연산자(<)가 쓰임.
	for(auto pos : xy) cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
	
}