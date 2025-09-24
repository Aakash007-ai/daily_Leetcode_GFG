#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool meetingSort(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        pair<int,int> meetingA = a.second;
        pair<int,int> meetingB = b.second;

        if(meetingA.second <= meetingB.second) return true;
        return false;
    }

    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        int n = start.size();
        if(n <= 1) return n;
        vector<pair<int,pair<int,int>>> meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({i+1,{start[i],end[i]}});
        }

        sort(meetings.begin(), meetings.end(), meetingSort);

        int meetingCnt = 1;
        pair<int,pair<int,int>> prevMeeting = meetings[0];
        for(int i=1;i<n;i++){
            if(prevMeeting.second.second < meetings[i].second.first){
                meetingCnt++;
                prevMeeting = meetings[i];
            }
        }
        return meetingCnt;
    }

};