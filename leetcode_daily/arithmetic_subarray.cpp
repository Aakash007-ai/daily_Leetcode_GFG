#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int s=l[i];
            int e=r[i];
            if(s<e){
                //then only solve next
                vector<int> v(nums.begin()+s,nums.begin()+e);
                int diff=v[1]-v[0];
                for(int i=1;i<nums.size();i++){
                    if(v[i]-v[i-1] != diff){
                        //not a arithmetic got our answer break loop
                        ans.push_back(false);
                        break;
                    }
                }
            ans.push_back(true);
            }else{
                ans.push_back(true);
            }
            
        }
        return ans;
    }
};