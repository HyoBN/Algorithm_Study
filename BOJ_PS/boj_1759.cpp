#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
vector<char> v; 
vector<char> res;

bool check()
{
    int moum = 0;
    for(int i = 0 ; i< l ; i++)
        if(res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u')
           moum++;
    if(moum >=1 && l-moum >=2) return true; 
    return false;
}

void dfs(int x){
    if((int)res.size()==l){
        if(check()){ 
            for(int k = 0 ; k< l ; k++)
				cout << res[k];
			cout << '\n';
        }
        return;
    }
    for(int i = x ; i< c; i++)
    {
        res.push_back(v[i]); 
        dfs(i+1);
        res.pop_back();
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l  >> c;
    for(int i = 0 ; i< c ; i++)
    {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end()); 
    dfs(0);
}