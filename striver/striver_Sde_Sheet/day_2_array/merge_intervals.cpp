#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        if(a.front()< b.front()) return true;
        else if(a.front() == b.front()){
            return a.back()>b.back();
        }
        return false;
    }
    // static bool comp(vector<int> a, vector<int> b){
    //     if(a.front() <= b.front()) return true;
    //     return false;
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        ans.push_back(intervals.front());
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = ans.back();

            int sIdx = temp.front();
            int eIdx = temp.back();

            // if new starting point is less then ending of other
            if(intervals[i].front() <= eIdx){
                //check if partial merge or fully merge
                if(intervals[i].back() <= eIdx){ //fully merge do nothing
                    continue;
                }else{ //update ans
                    ans.pop_back();
                    ans.push_back({sIdx,intervals[i].back()});
                }
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

//give runtime error