#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
    priority_queue<int , vector<int>, greater<int>> pq;
    for(auto it: nums1){
      for(auto it2: nums2){
        pq.push(it+it2);
        if(pq.size()>k) pq.pop();
      }
    }

    vector<int> ans;
    while(!pq.empty()){
      ans.push_back(pq.top());pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
  }
};