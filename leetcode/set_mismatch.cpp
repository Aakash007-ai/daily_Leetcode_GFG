#include<bits/stdc++.h>
using namespace std;

// a number is missing and one is duplicate 
//so xor of same number is 0


//brute force 
// unordered map of 1 to n with initial value=0
// then iterate over array

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
     unordered_map<int,int> mp;
        for(int i=1;i<=nums.size();i++){
            mp[i]=0;
        }
        for(auto it:nums){
            mp[it]++;
        }
        int twice,emp;
        for(auto it:mp){
            if(it.second==0) emp=it.first;
            if(it.second==2) twice=it.first;
        }
        return {twice,emp};
    }
};