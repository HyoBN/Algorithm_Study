#include <iostream>
#include <cmath>
using namespace std;

bool broken_button[10];

int check(int n)
{
    if(n==0)
	{
        if(broken_button[0])
            return 0;
        else
            return 1;
    }
 
    else
	{
        int len=0;
        while(n>0){
            if(broken_button[n%10]) // 고장난 버튼에 해당되면.
                return 0;
            n /=10;
            len+=1;
        }
        return len;
    }
}
 
int main(void){
    int channel,m;
    cin>>channel>>m;
	
    for(int i=0; i<m; i++){ //고장난 버튼 입력받음.
        int j;
        cin>>j;
        broken_button[j]=true;
    }
 
    int result = abs(100-channel); //목표 채널을 맞추기 위해 보정해야하는 값.
	
    for(int i=0;i<=1000000; i++)
	{
        int len = check(i);
        if(len>0)
		{
            int press = abs(channel-i);
            result = min(result,press+len);
        }
    }
    cout<<result;
}