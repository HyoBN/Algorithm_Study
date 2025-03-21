#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int arr[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n =triangle.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<triangle[i].size();j++){
            arr[i][j]=triangle[i][j];
        }
    }
    
    if(n<3){ // 높이 1 또는 2인 경우.
        answer = arr[0][0] + max(arr[1][0],arr[1][1]);
    }
    
    else{
        for(int i=1;i<n;i++){
            arr[i][0]+=arr[i-1][0];
            arr[i][i]+=arr[i-1][i-1];
        }
        
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                arr[i][j] += max(arr[i-1][j-1],arr[i-1][j]);
            }
        }

    }
    
    for(int i=0;i<n;i++){
        answer = max(answer, arr[n-1][i]);
    }
    
    return answer;
}
