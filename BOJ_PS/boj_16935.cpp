#include <iostream>
#include <cmath>
using namespace std;

// 최소 단위의 연산을 구현하고, 해당 연산들로만 모든 연산 유도하기
// 좌우 대칭, 상하 대칭, 대각선 대칭

int n,m,r;
int arr[101][101];

void upDown(){
    int temp[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j]=arr[n-i-1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j]=temp[i][j];
        }
    }
}
void leftRight(){
    int temp[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j]=arr[i][m-j-1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j]=temp[i][j];
        }
    }
}

void diagonal(){
    int temp[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][i]=arr[i][j];
        }
    }
    int tempNum;
    tempNum=n;
    n=m;
    m=tempNum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j]=temp[i][j];
        }
    }
}
void rotateCW(){
    diagonal();
    leftRight();
}

void rotateCCW(){
    int a=3;
    while (a--)rotateCW();
}

void five(){
    int temp[101][101];
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            temp[i][j]=arr[i+n/2][j];
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) {
            temp[i][j] = arr[i][j - m / 2];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) {
            temp[i][j] = arr[i - n / 2][j];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            temp[i][j] = arr[i][j + m / 2];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j]=temp[i][j];
        }
    }
}
void six(){
    int a=3;
    while(a--) five();
}

int main(){
    cin>>n>>m>>r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        int num;
        cin>>num;
        if(num==1) upDown();
        else if(num==2) leftRight();
        else if(num==3) rotateCW();
        else if(num==4) rotateCCW();
        else if(num==5) five();
        else if(num==6) six();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}
