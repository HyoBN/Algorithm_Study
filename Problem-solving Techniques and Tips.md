## Problem-Solving Techniques and Tips

PS를 하며 유용하게 사용할 수 있는 메소드나 기법, 알게 된 점 등 기억하고 활용할 만한 모든 내용을 정리.  

### 1. 메소드

#### stoi 함수
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

#### to_string 함수
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

#### sort 함수
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

#### stable_sort 함수
 - 같은 키 값을 가지는 노드들이 sorting 된 후 순서가 바뀌지않도록(stable) 정렬해주는 함수.
 - 일반 sort 함수의 경우 quick sort를 기반으로 하기 때문에 unstable하다.
 - (분할 정복 방식으로 구현한 quick sort의 동작 과정을 생각해보면 unstable하다는 것을 깨달을 수 있다.)
 - stable한 정렬인 merge sort를 기반으로 한다.
 - 사용 방법은 sort함수와 동일, sort 를 stable_sort로 바꾸어 주면 된다.
 - ex) stable_sort(arr,arr+5,desc);
 
 - 해시태그) #정렬 #머지소트 #merge_sort #stable
 
 
#### pair 클래스
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
 
 
#### round 함수
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
------
### 2. 참신한 기법

------
### 3. 문제 조건 맞추기
ex) 시간 단축, 메모리 최적화, 자료형 설정.  

#### 시간 단축

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
### 4. 알쓸신잡(알아두면 쓸데'있'는 신비한 잡지식)
ex) 위에 분류되기엔 좀 애매한, 하지만 알아두면 좋은 내용들을 정리.

#### #include<헤더파일> 과 #include "헤더파일" 의 차이점.

1. #include <헤더파일>은 '컴파일러가 설치된 폴더'에서 해당 헤더 파일을 찾으라는 지시이다.
2. #include "헤더파일"은 '현재 소스 파일이 존재하는 폴더에서 해당 헤더 파일을 먼저 찾고 없으면 '컴파일러가 설치된 폴더'에서도 찾는다.
 - 사용자가 만든 헤더파일이나 추가 외부 라이브러리를 포함하고 싶은 경우 사용한다.
