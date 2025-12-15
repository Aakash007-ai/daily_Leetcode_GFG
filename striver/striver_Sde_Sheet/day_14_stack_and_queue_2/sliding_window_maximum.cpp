#include<bits/stdc++.h>
using namespace std;

// make it fast slow now
void printVector(vector<int> &nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int j = 0;
        int n = nums.size();

        map<int,int , greater<int>> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            
            if(i-j+1 > k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            
            if(i-j+1 == k){
                ans.push_back(mp.begin()->first);
            }
        }
        return ans;
    }
};


int main(){
    int n,k;
    cin>>n;
    vector<int> sam(n);
    for(int i=0;i<n;i++){
        cin>>sam[i];
    }
    cin>>k;
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(sam,k);
    printVector(ans);
}
