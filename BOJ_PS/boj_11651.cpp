#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    pair<int, int> p[1000001];
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&p[i].second,&p[i].first);
// pair sort할 때는 first가 같으면 second를 비교하기 때문에 문제 조건을 만족하기 위해 순서를 바꾸어 입력받음.

    sort(p,p+n);
    
    for(int j=0;j<n;j++)
        printf("%d %d\n",p[j].second,p[j].first);
}
