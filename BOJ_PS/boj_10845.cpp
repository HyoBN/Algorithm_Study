#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,num;
	int top_pointer=0;
	int tail_pointer=0;
	int arr[100001];
	string str;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>str;
		
		if(str=="push"){
			cin>>num;
			arr[tail_pointer++]=num;
		}
		else if(str=="pop"){
			if(tail_pointer-top_pointer==0)
				cout<<-1<<endl;
			else
				cout<<arr[top_pointer++]<<endl;
		}
		else if(str=="size")
			cout<<tail_pointer-top_pointer<<endl;
		else if(str=="empty")
			tail_pointer-top_pointer==0 ? (cout<<1<<endl) : (cout<<0<<endl);
		else if(str=="front"){
			if(tail_pointer-top_pointer==0)
				cout<<-1<<endl;
			else
				cout<<arr[top_pointer]<<endl;
		}
		else if(str=="back"){
			if(tail_pointer-top_pointer==0)
				cout<<-1<<endl;
			else
				cout<<arr[tail_pointer-1]<<endl; // -1을 한 이유는 push하면 tail이 +1되면서 다음 push지점을 가리키기때문.
		}
		
	}
	return 0;
}
