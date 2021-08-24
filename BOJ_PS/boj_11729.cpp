#include <iostream>
using namespace std;

void hanoi(int n, int start, int tmp, int to)
{
    if(n==1)
        printf("%d %d\n", start, to);
    else
    {
        hanoi(n-1,start,to,tmp);
        printf("%d %d\n",start,to);
        hanoi(n-1,tmp,start,to);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    hanoi(n,1,2,3);
}