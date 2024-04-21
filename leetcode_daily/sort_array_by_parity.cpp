#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> ans;
        for(auto it:nums){
            if(it%2== 0){
                ans.push_back(it);
            }else{
                odd.push_back(it);
            }
        }
        ans.insert(ans.end(),odd.begin(),odd.end());
        return ans;
    }
};

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Solution obj;
    obj.sortArrayByParity(v);
}