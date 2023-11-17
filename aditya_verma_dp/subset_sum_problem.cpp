#include<bits/stdc++.h>
using namespace std;

// bool solve(vector<int> &arr,int sum,int n){
//             if(sum == 0) return true;
//             if(n<=0) return false;

//             if(sum>=arr[n-1]){
//                 return solve(arr,sum-arr[n-1],n-1) || solve(arr,sum,n-1);
//             }
//             return solve(arr,sum,n-1);
// }
// bool isSubsetSum(vector<int>arr, int sum){
//     return solve(arr,sum,arr.size()); 
// }


// class Solution {
//     public:
//     bool isSubsetSum(vector<int> arr,int sum){
//         vector<vector<int>> dp(arr.size()+1,vector<int> (sum+1));
//         int n=arr.size();
//         for(int i=0;i<=n;i++){
//             dp[i][0] = true;
//         }
//         for(int i=0;i<=sum;i++){
//             dp[0][i] =false;
//         }
//         dp[0][0]=true;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=sum;j++){
//                 if(j>=arr[i]){
//                     dp[i][j]= (sum-arr[j-1])
//                 }
//             }
//         }
//     }
//         // int solve(vector<int> &arr,int sum,int n,vector<int> &dp){
//         //     if(sum == 0) return 1;
//         //     if(n<=0) return 0;
//         //     if(dp[n] != -1) return dp[n];
//         //     if(sum>=arr[n-1]){
//         //         return dp[n]=solve(arr,sum-arr[n-1],n-1,dp) + solve(arr,sum,n-1,dp);
//         //     }
//         //     return dp[n]=solve(arr,sum,n-1,dp);
//         // }
//         // bool isSubsetSum(vector<int>arr, int sum){
//         //     vector<int> dp(arr.size()+1,-1);
//         //     return dp[arr.size()]=solve(arr,sum,arr.size(),dp); 
//         // }
// };




class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
        // for(int i=0;i<=sum;i++){
        //     dp[0][i]=0;
        // }
        for(int j=0;j<=n;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
        }
        return dp[n][sum];
    }


    // bool solve(vector<int> &arr, int sum, int n,vector<vector<int>> &dp){
    //     //base consition 
    //     if(sum==0) return 1;
    //     if(n==0) return 0;
    //     if(dp[n][sum] !=-1) return dp[n][sum];
    //     if(arr[n-1]>sum){
    //         return dp[n][sum]=solve(arr,sum,n-1,dp);
    //     }
    //     return dp[n][sum]=solve(arr,sum-arr[n-1],n-1,dp) || solve(arr,sum,n-1,dp);
    // }
    // // find wheteher the array has a subset with given sum
    // bool isSubsetSum(vector<int>arr, int sum){
    //     vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
    //     dp[arr.size()][sum]=solve(arr,sum,arr.size(),dp);
    //     if(dp[arr.size()][sum]==1) return true;
    //     return false; 
    // }
};

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;cin>>sum;
    Solution obj;
    cout<<obj.isSubsetSum(arr,sum);
}