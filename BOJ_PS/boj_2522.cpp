#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

            
        for(int b=0;b<n-i-1;b++)
            printf(" ");
            
        for(int c=0;c<=i;c++)
            printf("*");
        printf("\n");
    }
    for(int j=1;j<n;j++){

        for(int e=0;e<j;e++)
            printf(" ");
        for(int f=0;f<=n-j-1;f++)
            printf("*");
                        
        printf("\n");
    }
    
}