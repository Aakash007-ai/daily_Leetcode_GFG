#include<bits/stdc++.h>
using namespace std;

/**
 * so we first sort meeting by their ending time , be we want train left as early as possible
 * 
 * iterating over sorted timings
 * 
 * so idea is taking a queue and putting item in next item it , if any train left (check new timings after inserting current) 
 * 
 * then fanout train, maximum size of queue is the number of platform required
 */

class Solution{
    public:
    static bool timingsSort(pair<int,int> a, pair<int,int> b){
        if(a.second < b.second) return true;
        else if(a.second == b.second) a.first>b.first;
        return false;
    }

    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n =Arrival.size();
        vector<pair<int,int>> timings;
        for(int i=0;i<Arrival.size();i++){
            timings.push_back({Arrival[i],Departure[i]});
        }

        sort(timings.begin(), timings.end(), timingsSort);

        queue<pair<int,int>> q;
        int i=0;
        q.push(timings[i++]);
        int platformCnt = 1;
        
        while(i<n){
            pair<int,int> newTrain = timings[i];
            while(q.size() && q.front().second < newTrain.first){
                q.pop();
            }
            q.push(newTrain);
            platformCnt = max(platformCnt, (int)q.size());
        }
        return platformCnt;
    }
};