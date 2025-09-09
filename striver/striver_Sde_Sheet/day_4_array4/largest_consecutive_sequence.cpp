#include<bits/stdc++.h>
using namespace std;

/**
 * approach was sort array first then sliding window, tc nlog for sorting
 * 
 * but it is given time complexity should be o(n), our experience was when 
 * time complexity will increased , space complexity decreased
 * 
 * space complexity increased time complexity decreased
 * 
 * 
 * but in our question we are forced to do nested loop, 
 * but hack is that we can use condition on our nested loop, only use to find solution , not for permutation
 * 
 * also we have to reduce t.c. using hash set , so instead of handling with duplicates we deal with unique only
 * 
 * 
 * so we have to do in such a way finding element should not constitute in overall t.c
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;
        int maxCons = 0;
        for(auto it:nums){

            // we only interested for those elements which are the starting point
            if(st.find(it-1) == st.end()){
                //now count for next elements and find the longest length
                int curr = it+1;
                int len = 1;
                while(st.find(curr) != st.end()){
                    // increment len and num
                    curr++;
                    len++;
                }
                maxCons = max(maxCons,len);
            }
        }
        return maxCons;
    }
};