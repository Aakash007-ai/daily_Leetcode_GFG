#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &it:nums) it *=it;

        sort(nums.begin(),nums.end());

        return nums;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    vector<int> ans = obj.sortedSquares(arr);

    for(auto it:ans) cout<<it<<" ";
}