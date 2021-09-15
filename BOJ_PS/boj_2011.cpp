#include<iostream>
#include<string>
#define mod 1000000
using namespace std;

int main(){
    int x;
	int dp[5001] = {1,1};
	string s;
	cin>>s;
	
    if(s[0]=='0'){
        cout<<0;
		return 0;
    }
		
    for(int i=2; i<=s.size(); i++)
	{
        if(s[i-1]>'0') dp[i]=dp[i-1]%mod;
        
        x =(s[i-2]-'0')*10 + s[i-1]-'0';
        if(10<=x && 26>=x)
            dp[i] = (dp[i]+dp[i-2])%mod; 
    }
    cout<<dp[s.size()];
}