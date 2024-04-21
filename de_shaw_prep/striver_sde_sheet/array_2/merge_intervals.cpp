#include<bits/stdc++.h>
using namespace std;

/*
    merge intervals
    so we have a vector of vector of int
    we sort it so that next element is equal to or greater than prev element
    case :- [1,5] [2,4] so basically we comapre first of next with last of prev
    if(intervals[i].first < intervals[i-1].end())
*/
class Solution {
public:
    // bool comp(vector<int> a,vector<int> b){

    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            //if this interval start in between of prev then merge
            if(ans.back().back() >= intervals[i].front()){
                //then sore maximum of back
                ans.back().back() = max(ans.back().back(),intervals[i].back());
            }else{//we have a fresh new interval
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};