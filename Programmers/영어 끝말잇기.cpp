#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> savedWords;
    char endChar;
    int num=0,iter=0;
    
    savedWords.push_back(words[0]);
    endChar = words[0][words[0].length()-1];
    
    for(int i=1;i<words.size();i++){
        string nowWord = words[i];
        if(nowWord[0]==endChar 
           && find(savedWords.begin(),savedWords.end(),nowWord)==savedWords.end()){
            
            savedWords.push_back(nowWord);
            endChar = nowWord[nowWord.length()-1];
        }
        else{
            
            if((i+1)%n==0){
                num=n;
            } else num=(i+1)%n;
            
            iter = (i+1)/n+1;
            if((i+1)%n==0) iter -=1;
            
            
            break;
        }
    }
    answer.push_back(num);
    answer.push_back(iter);
    
    
    return answer;
}
