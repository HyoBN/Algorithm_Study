# Problem-Solving Techniques and Tips

PS를 하며 유용하게 사용할 수 있는 메소드나 기법, 알게 된 점 등 기억하고 활용할 만한 모든 내용을 정리. 

-------------
## TOC

1. [메소드](#1-메소드)
2. [참신한 기법](#2-참신한-기법)
3. [문제 조건 맞추기](#3-문제-조건-맞추기)
4. [유용한 TMI](#4-유용한-TMI)

--------------

## 1. 메소드

### stoi 함수
 - string to int 말 그대로 문자열을 정수형으로 변환하는 함수.
 - string 헤더파일에 선언되어 있음.
 - stof, stoll 등 다른 정수 자료형으로도 변환 가능.
 - 사용 방법)
 
```c
#include <string>

int a;
string str;
a=stoi(str);
```
 - 해시태그) #문자열 #자료형변환

### to_string 함수
 - to string 말 그대로 정수를 문자열로 변환하는 함수.
 - string 헤더파일에 선언되어 있음.
 - int, float, long long 등 정수 자료형 모두 사용 가능.
 - 자릿수 연산에 많이 사용.
 - 사용 방법)
 
```c
#include <string>

int a;
string str;
str=to_string(a);
```
- 해시태그) #문자열 #자료형변환

### sort 함수
 - 지정 범위 안의 인자들을 정렬해주는 함수.
 - algorithm 헤더 파일에 선언되어 있다.
 - quick sort를 기반으로 하기 때문에 평균 시간 복잡도는 nlogn 이다.
 - 세 번째 매개변수를 통해 자신이 원하는 특정 변수 기준으로 원하는 방식으로 정렬할 수 있음.
 - 사용 방법)
 
```c
#include <algorithm>

bool desc(int a, int b){ //내림 차순 정렬을 위한 함수.
	return a<b;
}

int arr[5]={3,5,1,4,2};
sort(arr,arr+5)); //default : 오름차순. 매개변수로 배열의 시작점 주소, 마지막 주소+1을 전달.
sort(arr,arr+5,desc); // 내림차순. 세 번째 매개변수로 함수를 전달하여 자신이 원하는 형태로 정렬 기준을 설정할 수 있음.
```
 - 해시태그) #정렬 #퀵소트 #quick_sort #unstable

### stable_sort 함수
 - 같은 키 값을 가지는 노드들이 sorting 된 후 순서가 바뀌지않도록(stable) 정렬해주는 함수.
 - 일반 sort 함수의 경우 quick sort를 기반으로 하기 때문에 unstable하다.
 - (분할 정복 방식으로 구현한 quick sort의 동작 과정을 생각해보면 unstable하다는 것을 깨달을 수 있다.)
 - stable한 정렬인 merge sort를 기반으로 한다.
 - 사용 방법은 sort함수와 동일, sort 를 stable_sort로 바꾸어 주면 된다.
 - ex) stable_sort(arr,arr+5,desc);
 
 - 해시태그) #정렬 #머지소트 #merge_sort #stable
 
 
### pair 클래스
 - 두 객체를 하나의 객체로 취급할 수 있게 묶어주는 클래스이다.
 - 데이터 쌍을 표현할 때 자주 사용된다.
 - utility 헤더 파일에 선언되어 있다.
 - pair<int, pair<int,int>>와 같이 중첩하여 사용도 가능.
 - pair<int, string> 과 같이 다른 자료형도 묶을 수 있어서 유용함.
 - 사용 방법)
```c
#include <utility>
pair<int, int> p1;
p1=make_pair(1,2);
//p1={1,2}; 윗 줄과 동일.
cout<<p1.first; //1출력됨.
cout<<p1.second; // 2출력됨.
```
 - 해시태그) #pair #자료구조
 
 
### round 함수
 - 인자로 들어온 값을 반올림해서 반환하는 함수.
 - cmath 헤더 파일에 선언되어 있다.
 - 양수, 음수 상관 x
 - 사용 방법)
```c
#include <cmath>
double a=1.5;
round(a);
```
 - 해시태그) #반올림
 
### 스택
 - 말 그대로 자료구조 중 하나인 스택(Stack).
 - 데이터 삽입과 삭제 시 시간복잡도 : O(1) (상수시간).
 - 검색(Search)시 시간 복잡도 : O(n)
 - 스택과 벡터는 시간,공간 복잡도에 있어서 거의 차이가 없다.
 - stack 헤더파일에 선언되어 있다.
 - 메소드.
 	1. push(a) : top에 a를 추가.
	2. pop() : top에 있는 원소를 삭제. 출력하지 않고 삭제만 함.
	3. top() : 현재 top에 있는 원소를 반환.
	4. empty() : 스택이 비어있으면 true를 반환. 아님 false.
	5. size() : 현재 스택의 사이즈를 반환.
 - 사용 방법) 
 
```c
#include <stack>
stack<int> s;

s.push(1);
cout<<s.top(); // 1 출력.
s.pop();
if(s.empty()) cout<<"empty"; // empty 출력.
```
 - 해시태그) #스택 #Stack #자료구조

### 큐
 - 말 그래도 자료구조 중 하나인 큐(Queue).
 - 스택과 동일한 시간 복잡도를 가진다.
 - queue 헤더 파일에 선언되어 있다.
 - 메소드.
 	1. push(a) : 큐에 a를 추가.
	2. pop() : 큐의 front에 있는 원소 삭제.
	3. front() : 큐의 front에 있는 원소 반환.
	4. back() : 큐의 마지막 원소 반환.
	5. size() : 현재 큐의 사이즈 반환.
	6. empty() : 큐가 비어있으면 true를 반환.
	7. swap(q1, q2) : q1과 q2 두 큐의 내용을 바꿈.
 - 사용 방법)
 
```c
#include <queue>
queue<int> q1;
queue<int> q2;

q1.push(1);
q2.push(5);
cout<<q1.front();
swap(q1,q2);
```

 - 해시태그) #큐 #Queue #자료구조

### 순열, 조합
 - 순열(permutation) : n개의 원소 중, m개를 선택하여 한줄로 세우는 경우의 수, 순서 고려.
 - 조합(combination) : n개의 원소 중 m개를 뽑는 경우, 순서 상관x.
 - 순열과 조합의 모든 경우의 수를 출력해주는 메소드이다.
 - 주의할 점) 오름차순으로 정렬된 값을 가진 값들을 사용해야한다.
 - 오름차순으로 출력해준다.
 - algorithm 헤더 파일에 선언되어 있다.
 - 사용방법)


```c
//------------- 순열 구하기. 4P3
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[4]={1,2,3,4};
	sort(arr,arr+4);	
	do{
		for(int i=0;i<3;i++)
			cout<<arr[i]<<' ';
		cout<<'\n';
	}while(next_permutation(arr,arr+3));
	
}
```

```c
//------------- 조합 구하기. 4C3
#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[4]={1,2,3,4};
	int tmp[4]={0,0,0,1}; // m개의 원소를 0로, (n-m)개의 원소는 1로 초기화
	sort(arr,arr+4);
	do{
			for(int i=0;i<4;i++) //배열 원소 개수
				if(tmp[i]==0)
					printf("%d ",arr[i]);
			printf("\n");
	}while(next_permutation(tmp,tmp+4));
	
}
```

- 해시태그) #순열 #조합 #permutation #combination

------
## 2. 참신한 기법


### 2의 n승 구하기.
 - cmath 라이브러리의 pow 메소드를 활용하는 방법도 있지만, 단순히 2의 n승 값을 구해야 하는 경우,
 shift 연산을 활용하는 것이 더 빠르다.

```c
int a=5;
a=a<<1; // 2의 a승 / 1을 a만큼 shift
cout<<a;
```

- shift 연산은 비트 연산이며, 비트 연산은 기계어 레벨 즉, low level에서 연산이 진행되기 때문에 일반 연산이나 메소드들보다 빠르다.

```c

#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int main()
{
	clock_t start, end;
	double result;
	int a=50;
	long long b;

	start=clock();
	
	//b=pow(2,a);
	b=1<<a;
	
	cout<<b;
	
	end=clock();
	
	result=(double)(end-start);
	cout<<"result : "<<result;
}
```

- 위의 코드로 직접 실험해보았을 때, shift 연산이 pow 메소드보다 1.5~2배 정도 빠르다는 사실을 확인할 수 있었다.

------
## 3. 문제 조건 맞추기
ex) 시간 단축, 메모리 최적화, 자료형 설정.  

### 시간 단축

```c
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

1. 말 그대로 C 표준 stream과 C++ 표준 stream의 동기화를 끊는다.
 - 기본적으로 모든 표준 stream들은 동기화 되어 c++ stream들이 자신의 버퍼 대신
	그에 대응되는 c stream을 사용하여 c와 c++의 입출력 방식을 자유롭게 혼용 가능하다.
 - 이 동기화를 끊게되면 c++ stream이 독립적인 버퍼를 갖게되어 사용하는 버퍼의 수가 줄어든다.
	그로 인해 실행 속도가 크게 향상된다.
 - 주의할 점) c와 c++ 입출력 방식을 혼용하여 쓰면 입출력 순서를 보장하지 않는다.
	또한, multi-thread의 경우 안정성을 보장하지 않기 때문에 trash 값이 나올 수 있다.

2. cin.tie(NULL), cout.tie(NULL)
 - cin과 cout이 묶여 있는 것을 풀어준다. 즉, cin과 cout의 동기화를 해제한다.
 - 기존의 경우, cin과 cout이 tie된 상태여서 cout과 cin이 실행되지만 tie(NULL) 시키면
	cout이 실행되지 않고 cin만 실행된다고 한다. 실험해봤는데 cout도 잘됨...


```c
cout<<a<<endl; // 대신
cout<<a<<'\n'; // 쓰기!
```
 - endl은 버퍼를 비우기 때문에 자주 사용하면 느려진다.
 
> fast IO 참고 글 https://cgiosy.github.io/posts/fast-io

------

## 4. 유용한 TMI

위에 분류되기엔 좀 애매한, 하지만 알아두면 쓸데있는 지식들을 정리.  

### #include<헤더파일> 과 #include "헤더파일" 의 차이점.

1. #include <헤더파일>은 '컴파일러가 설치된 폴더'에서 해당 헤더 파일을 찾으라는 지시이다.
2. #include "헤더파일"은 '현재 소스 파일이 존재하는 폴더에서 해당 헤더 파일을 먼저 찾고 없으면 '컴파일러가 설치된 폴더'에서도 찾는다.
 - 사용자가 만든 헤더파일이나 추가 외부 라이브러리를 포함하고 싶은 경우 사용한다.

### 정규 표현식(Regular expression)
 : 특정한 규칙을 가진 문자열의 집합을 표현하는데 사용하는 형식 언어.

 - 특정한 조건이나 패턴이 있는 문자열을 간단하게 표현할 수 있다.
 - c++ 의 경우 C++ 11부터 사용 가능하다.
 - regex 헤더 파일에 선언되어 있다.
 
#### 장점
1. 입력받은 문자열을 간결하게 처리할 수 있다.
2. 정규 표현식은 다양한 언어와 프로그램에서 지원하기 때문에 범용성이 뛰어나다.
3. 실제 개발시 수많은 문서와 문자열을 처리해야하는데 정규 표현식을 잘 활용하면 생산성을 증대시킬 수 있다.

- 정규 표현식(c++로)을 사용할 기회가 생기면 참고할 글 : https://modoocode.com/303

### 배열의 크기(int arr[MAX])

- 배열의 크기는 컴파일타임(프로그램 실행 전 컴파일하는 시기)에 결정되어야 한다.
- 일반적인 변수 선언이나 const 상수는 런타임에 결정되므로(런타임 상수라 한다) 이를 사용하면 에러가 뜬다.
- 따라서, 전처리기 매크로 상수(#define)을 통해 정의할 수 있다.  ex) #define MAX 1000
	- #: 전처리 지시자. 즉, #define : 컴파일 이전에 정의하라
	- 주의할 점 : 세미콜론(;)을 붙이지 않는다.
-  c++은 const가 경우에 따라 런타임 상수도 될 수 있기 때문에 const 상수로 배열 크기를 선언하는 것이 가능하다.


### 컴파일 타임과 런타임.

#### 컴파일 타임(Compile time)
- 소스 코드가 기계어 코드로 변환되어 실행 가능한 프로그램이 되는 과정 즉, 컴파일 과정 시간을 컴파일 타임이라 한다.

- 컴파일 에러 : 프로그램이 성공적으로 컴파일되는 것을 방해하는 신택스에러나 파일참조 오류와 같은 에러.

#### 런 타임(Run time)
- 컴파일 과정을 마친 프로그램 즉, 응용프로그램이 동작되어지는 떄를 런 타임이라 한다.
- 런타임 에러 :예상치 못한 오류 또는 충돌 등을 이유로 성공적으로 컴파일 되었더라도 프로그램이 실행 중에 발생하는 형태의 에러.


### segmentation fault error

segmentation Fault는 세그멘테이션 위반으로, 세그폴트라고 줄여 쓰기도 한다.  

세그멘테이션 오류 (core dumped) 라는 메시지의 오류가 뜨는 경우 주된 원인은 다음과 같다.  
1. 프로그램이 허용하지 않은 메모리에 접근을 시도하였을 경우.
2. 허용되지 않은 방법으로 메모리 영역에 접근을 시도하였을 경우.

