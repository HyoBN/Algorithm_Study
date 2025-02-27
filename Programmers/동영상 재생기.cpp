#include <string>
#include <vector>
#include <iostream>
using namespace std;

int get_int_time(string time){
    return stoi(time.substr(0,2))*60 + stoi(time.substr(3,4));
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_start_time = 0;
    int video_end_time = get_int_time(video_len);
    int now_time = get_int_time(pos);
    int op_start_time = get_int_time(op_start);
    int op_end_time = get_int_time(op_end);
    
    if(op_start_time<=now_time && now_time<=op_end_time){
        now_time = op_end_time;
    }
    
    for(int i=0;i<commands.size();i++)
    {
        if(commands[i]=="prev"){
            now_time = max(now_time-10,video_start_time);
        }
        else if(commands[i]=="next"){
            now_time = min(now_time+10, video_end_time);
        }
        if(op_start_time<=now_time && now_time<=op_end_time){
        now_time = op_end_time;
        }
    }
    if(now_time/60<10){
        answer+= "0" + to_string(now_time/60);
    } else answer += to_string(now_time/60);
    
    answer +=":";
    if(now_time%60<10){
        answer+= "0" + to_string(now_time%60);
    } else answer += to_string(now_time%60);
    
    return answer;
}
