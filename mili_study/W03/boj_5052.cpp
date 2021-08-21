#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    int n,t;
	string tmp;
    cin >> t;
    vector<string> v;
    
    while(t--) {
        bool flag = true;
        cin >> n;
        
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
 
        for (int k = 0; k < v.size()-1; k++) { 
            if (v[k + 1].substr(0, v[k].length())== v[k]) {
                flag = false;
                cout << "NO\n";
                break;
            }
        }
        if (flag==true) 
            cout << "YES\n";
        v.clear();
    }
}