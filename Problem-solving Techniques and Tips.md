## Problem-Solving Techniques and Tips

PS를 하며 유용하게 사용할 수 있는 메소드나 기법, 알게 된 점 등  
기억하고 활용할 만한 모든 내용을 정리.  

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
- 해시태그) #문자열 #변환

#### to_string 함수
 - to string 말 그대로 정수를 문자열로 변환하는 함수.
 - string 헤더파일에 선언되어 있음.
 - int, float, long long 등 정수 자료형 모두 사용 가능.
 - 사용 방법)
 
```c
#include <string>

int a;
string str;
str=to_string(a);
```
- 해시태그) #문자열 #변환


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
 
fast IO 참고 글 https://cgiosy.github.io/posts/fast-io

------
### 4. 알쓸신잡(알아두면 쓸데'있'는 신비한 잡학사전)
ex) 위에 분류되기엔 좀 애매한, 하지만 알아두면 좋은 내용들을 정리.