#include<bits/stdc++.h>
using namespace std;


//so we find the mamum no. of candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=*max_element(candies.begin(),candies.end());
        cout<<mx;
        int n=candies.size();
        vector<bool> ans;
        for(auto it:candies){
            if(it+extraCandies>=mx){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

int main(){
    int n;cin>>n;
    vector<int> candies(n);
    for(int i=0;i<n;i++){
        cin>>candies[i];
    }
    int extraCandies;cin>>extraCandies;
    Solution obj;
    auto ans=obj.kidsWithCandies(candies,extraCandies);
    for(auto it:ans){
        cout<<it<<" ";
    }
}