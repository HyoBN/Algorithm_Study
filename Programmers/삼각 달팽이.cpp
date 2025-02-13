#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[1001][1001];
int dy[3] = {0,1,-1};
int dx[3] = {1,-1,0};

vector<int> func(int n){
    vector<int> v;
    for(int i=n-1;i>=0;i--){
        arr[i][0]=n-i;
    }
    int dir=0;
    int num=n+1;
    int y=0;
    int x=0;

    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++){
            y = y+dy[dir];
            x = x+dx[dir];
            arr[y][x]=num++;
        }
        dir = (dir+1)%3;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n-i;j++){
            v.push_back(arr[i][j]);
        }
    }
    return v;
}

vector<int> solution(int n) {
    vector<int> answer;
    answer = func(n);
    return answer;
}
