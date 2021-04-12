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
        scanf("%d %d",&p[i].first,&p[i].second);

    sort(p,p+n);
    
    for(int j=0;j<n;j++)
        printf("%d %d\n",p[j].first,p[j].second);
}
