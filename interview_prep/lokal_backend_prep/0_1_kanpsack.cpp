#include<bits/stdc++.h>
using namespace std;

    // int knapSack(int W, int wt[], int val[], int n) { 
    //     vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=W;j++){
    //             if(wt[i-1]>j){
    //                 dp[i][j]= dp[i-1][j];
    //             }else{
    //                 dp[i][j]= max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
    //             }
    //         }
    //     }
    //    return dp[n][W];
    // }

class Solution{
    public:
    int knapSack(int W,vector<int> wt,vector<int> val,int n){
        vector<vector<int>> dp(W+1,vector<int>(n+1,0));
        for(int i=1;i<=W;i++){
            for(int j=1;j<=n;j++){
                if(wt[j-1]<=i){
                    dp[i][j]=max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[W][n];
    }
};


int main(){
    int n;cin>>n;
    int W;cin>>W;

    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    vector<int> wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
   
    Solution obj;
    //what are changing in recursion, its w and n
    // vector<vector<int>> dp(W+1, vector<int> (n+1,-1));
    cout<<obj.knapSack(W,wt,val,n);
}



//memoization
// class Solution
// {
//     public:

//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, vector<int> wt,vector<int> val, int n,vector<vector<int>> &dp) { 
//        if(n==0) return 0;// if nothing is in bag return 0
//        if(W==0) return 0; // also if weight become 0 we can't pick anything
//        if(dp[W][n]!= -1) return dp[W][n];// what if we have already get the max value for W and n

//        if(wt[n-1]<=W){// now weight of bag is more than current index weight 
//         //so we have 2 choice , either to take that item in bag or skip that item
//         // and we want max of value we get from both choice
//         return dp[W][n]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1,dp), knapSack(W,wt,val,n-1,dp));
//        }
//        return dp[W][n]=knapSack(W, wt, val,n-1,dp);
//     }
// };


// int main(){
//     int n;cin>>n;
//     int W;cin>>W;

//     vector<int> val(n);
//     for(int i=0;i<n;i++){
//         cin>>val[i];
//     }

//     vector<int> wt(n);
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
   
//     Solution obj;
//     //what are changing in recursion, its w and n
//     vector<vector<int>> dp(W+1, vector<int> (n+1,-1));
//     cout<<obj.knapSack(W,wt,val,n,dp);
// }




// normal recursion
// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, vector<int> wt,vector<int> val, int n) { 
//        if(n==0) return 0;// if nothing is in bag return 0
//        if(W==0) return 0; // also if weight become 0 we can't pick anything

//        if(wt[n-1]<W){// now weight of bag is more than current index weight 
//         //so we have 2 choice , either to take that item in bag or skip that item
//         // and we want max of value we get from both choice
//         return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));
//        }
//        return knapSack(W, wt, val,n-1);
//     }
// };


// int main(){
//     int n;cin>>n;
//     int W;cin>>W;

//     vector<int> val(n);
//     for(int i=0;i<n;i++){
//         cin>>val[i];
//     }

//     vector<int> wt(n);
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
   
//     Solution obj;
//     cout<<obj.knapSack(W,wt,val,n);
// }








//          normal array

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// 0- 1 knapsack 
// we have some weight and their corresponding values
// maximise the value we can get from there
// maximise and we have choice

// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) { 
//        if(n==0) return 0;// if nothing is in bag return 0
//        if(W==0) return 0; // also if weight become 0 we can't pick anything

//        if(wt[n-1]<W){// now weight of bag is more than current index weight 
//         //so we have 2 choice , either to take that item in bag or skip that item
//         // and we want max of value we get from both choice
//         return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));
//        }
//        return knapSack(W, wt, val,n-1);
//     }
// };


// int main(){
//     int n;cin>>n;
//     int W;cin>>W;

//     int val[n];
//     for(int i=0;i<n;i++){
//         cin>>val[i];
//     }

//     int wt[n];
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
   
//     Solution obj;
//     cout<<obj.knapSack(W,wt,val,n);
// }