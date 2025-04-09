#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int getTimeByMinute(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,4));
    int timeByMinute = hour*60 + minute;
    return timeByMinute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> timeTable;
    for(int i=0;i<book_time.size();i++){
        int startTime = getTimeByMinute(book_time[i][0]);
        int endTime = getTimeByMinute(book_time[i][1]);
        
        timeTable.push_back({startTime,endTime});
    }
    sort(timeTable.begin(),timeTable.end());

    vector<int> room;
    
    for(pair<int,int> p : timeTable){
        bool chk = true;
        for(int i=0;i<room.size();i++){
            if(p.first >=room[i]){
                room[i]=p.second+10;
                chk=false;
                break;
            }
        }
        if(chk) room.push_back(p.second+10);
    }
    
    return room.size();
}
