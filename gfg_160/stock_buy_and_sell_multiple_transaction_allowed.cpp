#include<bits/stdc++.h>
using namespace std;

/*
    try using local maxima and local minima approach
    int i=0;
        int n=prices.size();
        int lMin = prices[i];
        int lMax = prices[i];
        int ans = 0;
        while(i<n-1){
            
            while(i<n-1 && prices[i] >= prices[i+1]){
                i++;
            }
            lMin = prices[i];
            
            while(i<n-1 && prices[i] <= prices[i+1]) i++;
            lMax = prices[i];
            
            ans = max(lMax-lMin, ans);
            i++;
            
        }
        return ans;
*/

class Solution {
    private:
    //     int solve(vector<int> & prices ,int i,bool buy,vector<vector<int>> &dp){
    //     if(i==prices.size()) return 0;

    //     //there are 2 choices , either buy or sell
    //     // only able to sell if we buy anyone
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy){
    //     return dp[i][buy]= max(-prices[i] + solve(prices,i+1,!buy,dp), solve(prices,i+1,buy,dp));
    //     }
    //     return dp[i][buy]= max(prices[i] + solve(prices,i+1,!buy,dp),solve(prices,i+1,buy,dp));
    // }

    // public:
    //     int maximumProfit(vector<int> &prices) {
    //         vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
    //         return solve(prices,0,true,dp);
    //     }

    //normal recursive problem
    // private:
    // int solve(vector<int> & prices ,int i,bool buy){
    //     if(i==prices.size()) return 0;

    //     //there are 2 choices , either buy or sell
    //     // only able to sell if we buy anyone
    //     if(buy){
    //     return max(-prices[i] + solve(prices,i+1,!buy), solve(prices,i+1,buy));
    //     }
    //     return max(prices[i] + solve(prices,i+1,!buy),solve(prices,i+1,buy));
    // }

    // public:
    // int maximumProfit(vector<int> &prices) {
    //     return solve(prices,0,true);
    // }
};

// int main(){
//     Solution obj;
//     int n;cin>>n;
//     vector<int> prices(n);
//     for(int i=0;i<n;i++){
//         cin>>prices[i];
//     }
//     cout<<obj.maximumProfit(prices);
// }