#include<bits/stdc++.h>
using namespace std;
/*
    basic step make tree and solve for small input

    first assume we have some items N>0  and then we can think whether we have option to choose last element
    then we have choice whether we are picking last element or not and solve for 1 less element
    then we get max of choosing left or right
    else if weight condition is not satisfying then
    solve for less input 
    if we have no input to solve return 0
    
    we have items to choose or not to choose
    i can choose only when w is >= weight[n-1] than I have choose solve for next solve(W-weight[N-1],weight,value,N-1) + value[N-1]
    not choosing nth skipping it

*/

class Solution
{
    public:
    //top down
    //Function to return max value that can be put in knapsack of capacity W.
    // here after declaring table we intilaize them also with initial value
    //then convert n, w to i and j and prev call to dp[n-1][j] or dp[n-1][j-1] or dp[n][j-1]
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]>j){
                    dp[i][j]= dp[i-1][j];
                }else{
                    dp[i][j]= max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
            }
        }
       return dp[n][W];
    }





    
    //memoization , bottom up
    //we  declare a vector of those variable which are changing and we have to store them
    //so, we declare a vector of size n+1 and W+1 as we can stor [n][w] from n-1, assuming 1 based index(easy to visiualize and solve and also for initializtion )
    //     int solve(int W, int wt[], int val[], int n,vector<vector<int>> &dp) 
    // {
    //     if(dp[n][W] != -1) return dp[n][W];     
    //    // Your code here
    //    if(n==0) return 0;
    //    if(W==0) return 0;

    //    if(wt[n-1]>W){
    //     return dp[n][W]=knapSack(W,wt,val,n-1);
    //    }
    //    return dp[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    // }

    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //     vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    //    // Your code here
    //    dp[n][W]=solve(W,wt,val,n,dp);
    //    return dp[n][W];
    // }

    //recursion
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //    // Your code here
    //    if(n==0) return 0;
    //    if(W==0) return 0;

    //    if(wt[n-1]>W){
    //     return knapSack(W,wt,val,n-1);
    //    }
    //    return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    // }
};

int main(){
    int n,w;
    cin>>n>>w;
    // int n;cin>>n;
    // int w;cin>>w;
    // vector<int> value(n,3); //it by default fill with zeroes
    // cout<<value[0];
    // for(int i=0;i<n;i++){
    //     int x;cin>>x;
    //     value[i]=x;
    // }
    // vector<int> weight(n);
    // for(int i=0;i<n;i++){
    //     int x;cin>>x;
    //     weight[i]=x;
    // }
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    Solution ob;
    cout<<ob.knapSack(w,wt,val,n);
    // cout<<"n is : "<<n;
    // cout<<"\nw is : "<<w;
    // cout<<"\n values are : ";
    // for(auto it:value){
    //     cout<<it<<" ";
    // }
    // cout<<"\n weights are : ";
    // for(auto it:weight) cout<<it<<" ";
    // cout<<knapsack(w,weight,value,n);
}



// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//        // Your code here
//     }
// };