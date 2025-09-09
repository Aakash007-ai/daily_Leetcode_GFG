#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                //now 2 sumvetor
                // unordered_map<int,int> mp;
                unordered_set<int> st;
                int tempTarget = target - nums[i]-nums[j];
                for(int k=j+1;k<n;k++){
                    unordered_set<int>::iterator it = st.find(nums[k]);
                    if(it != st.end()){
                        ans.insert({nums[i],nums[j],tempTarget-nums[k],nums[k]});
                    }else{
                        st.insert(tempTarget - nums[k]);
                    }
                }
            }
        }
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};


int main(){
    vector<int> temp = {1,0,-1,-2,2};
    int target = 0;
    Solution sol = Solution();
    vector<vector<int>> ans =sol.fourSum(temp,target);

}