#include<bits/stdc++.h>
using namespace std;


//return length of longest consecutive sequence

//brute force sort array  then just 2 pointer , here pointer doesnot start from end, both start from start

// https://leetcode.com/problems/longest-consecutive-sequence/solutions/3171985/best-c-4-solution-hash-table-sorting-brute-force-optimize-one-stop-solution
//todo :- try at least first 2 methods
// class Solution {
//     public:
//         int longestConsecutive(vector<int>& nums) {
//             sort(nums.begin(),nums.end());
//             int n = nums.size();
//             int ans = 1;
//             int i=0,j=1;
//             while(j<n-1){
//                 if(nums[j]-nums[j-1] == 1){
//                     ans = max(ans,j-i+1);
//                     j++;
//                     continue
//                 }
//             }
//         }
//     };