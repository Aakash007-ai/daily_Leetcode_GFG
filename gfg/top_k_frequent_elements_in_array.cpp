#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
         vector<int> v;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto x:m)
        {
            q.push({x.second,x.first});
        }
        while(k!=0)
        {
            v.push_back(q.top().second);
            q.pop();
            k--;
        }
        return v;
    }
};

// class Comp{
//     public:
//     bool operator() (pair<int,int> a,pair<int,int> b){
//         if(a.second>b.second) return true;
//         else if(b.second == a.second) return a.first > b.first;
//         return false;
//     } 
// };

// class Solution {
//   public:
   
//     vector<int> topK(vector<int>& nums, int k) {
//         unordered_map<int,int> mp;
//         for(int it:nums) mp[it]++;

//         priority_queue<pair<int,int> ,vector<pair<int,int>> , Comp> pq;
//         for(auto it:mp){
//             pq.push(it);
//         }
//         vector<int> ans;
//         while(k-- && !pq.empty()){
//             int tp=pq.top().second;pq.pop();
//             ans.push_back(tp);
//         }
//         return ans;
//     }
// };