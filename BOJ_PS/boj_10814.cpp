#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp (pair<int, string> u, pair<int, string> v)
{
    return u.first < v.first;
}

int main()
{
    int n;
    cin >> n;

    pair<int, string> p[1000001];

    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    stable_sort(p, p+n, cmp);
//algorithm STL의 sort 메소드는 unstable한 quick sort기반이므로 문제 조건을 만족하기 위해 
//stable한 merge sort 기반인 stable_sort 메소드를 사용하였다.
//또한 stable_sort는 sort와는 다르게 정렬 함수를 꼭 써줘야한다.
//stable : 같은 값의 위치가 정렬 과정에서 뒤바뀌지 않는 것.
    for (int i = 0; i < n; i++)
        cout << p[i].first << " " << p[i].second << "\n";
}