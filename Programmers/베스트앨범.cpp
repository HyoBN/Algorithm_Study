#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;


bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

bool cmpVec(vector<pair<int,int>> a, vector<pair<int,int>> b){
    int a0 = a[0].second;
    int b0 = b[0].second;
    return a0>b0;
}

map<string,int> genreIdx;
vector<vector<pair<int,int>>> v(101);

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    int genreCount=0;
    
    for(int i=0;i<n;i++){
        if(genreIdx[genres[i]]==0)
        genreIdx[genres[i]] = genreCount++;
    }
    for(int i=0;i<n;i++){
        int idx = genreIdx[genres[i]];
        
        v[idx].push_back({i,plays[i]});
    }
    
    for(int i=0;i<n;i++){
        int summ=0;
        for(int j=0;j<v[i].size();j++){
            summ+=v[i][j].second;
        }
        v[i].push_back({-1,summ});
        sort(v[i].begin(),v[i].end(),cmp);
    }
    
    sort(v.begin(),v.begin()+n,cmpVec);

    for(int i=0;i<genreCount;i++){
        for(int j=1;j<=min((int)v[i].size()-1,2);j++){
            answer.push_back(v[i][j].first);
        }
    }
    
    
    return answer;
}
