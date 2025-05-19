#include<bits/stdc++.h>
using namespace std;

// 4
// 1 3
// 2 6
// 8 10
// 15 16

// 2
// 1 4
// 2 3

// 2
// 1 4
// 1 5
class Solution {
    private:
    static bool sortInterval(vector<int> &a,vector<int> &b){
        if(a.front() < b.front()) return true;
        else if(a.front() == b.front()){
            return a.back()<b.back();
        }
        return false;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),sortInterval);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]); 
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = ans.back();//;ans.pop_back();
            if(temp.back() >= intervals[i].front()){//merging condition
                ans.pop_back();
                ans.push_back({temp.front(), max(temp.back(),intervals[i].back())});
            }else{
                ans.push_back(intervals[i]);
            }
            // if(temp.back() < intervals[i].front()){
            //     //put new vector in answer
            //     ans.push_back(intervals[i]);
            // }else{
            //     temp.pop_back();
            //     temp.push_back(max(temp.back(), intervals[i].back()));
            //     ans.pop_back();
            //     ans.push_back(temp);
            // }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;//number of intervals 
    vector<vector<int>> samp;
    int first,last;
    for(int i=0;i<n;i++){
        cin>>first>>last;
        samp.push_back({first,last});
    }

    vector<vector<int>> ans = obj.merge(samp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].front()<<" "<<ans[i].back()<<endl;
    }
}