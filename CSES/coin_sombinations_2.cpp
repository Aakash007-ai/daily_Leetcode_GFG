#include<bits/stdc++.h>
using namespace std;

int solve(long long int n,long long int target,vector<long long int> &coins){//solved with 100%
    int MOD=1e9+7;
    vector<vector<int>> dp(n+1,vector<int> (target+1,0));
 
    for(int i=0;i<=n;i++){
        dp[i][0]=1;//if we have target is 0, then we can have 1 way to get that ans;
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]]%MOD+dp[i-1][j]%MOD;
                dp[i][j]  %= MOD;
            }
            else{
                dp[i][j]= dp[i-1][j]%MOD;
            }
      
        }
    }
    return dp[n][target];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    long long int n,target;
    cin>>n>>target;
    vector<long long int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<solve(n,target,coins);
}



int MOD=1e9+7;
 

int solve(int n,int target,vector<int> &coins){
    vector<vector<int>> dp(n+1,vector<int> (target+1,0));
    
    if(target==0) return 1;
    if(n==0) return 0;
 
    for(int i=0;i<=target;i++){
        dp[0][target]=0; //if we have number of coins 0. then we can't sum up that so dp[0][target] ways to get that target is 0
    }
 
    for(int i=0;i<=n;i++){
        dp[i][0]=1;//if we have target is 0, then we can have 1 way to get that ans;
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]]%MOD+dp[i-1][j]%MOD;
            }
            else{
                dp[i][j]= dp[i-1][j]%MOD;
            }
            dp[i][j]  %= MOD;
        }
    }
    return dp[n][target];
}
 
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<solve(n,target,coins);
}



// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     long long int n,target;
//     cin>>n>>target;
//     vector<long long int> coins(n);
//     for(long long i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     cout<<solve(n,target,coins);
// }







// int MOD=1e9+7;
// // top down
// int solve(int n,int target,vector<int> &coins){
//     vector<vector<int>> dp(n+1,vector<int> (target+1,0));
    
//     if(target==0) return 1;
//     if(n==0) return 0;

//     for(int i=0;i<=target;i++){
//         dp[0][target]=0; //if we have number of coins 0. then we can't sum up that so dp[0][target] ways to get that target is 0
//     }

//     for(int i=0;i<=n;i++){
//         dp[i][0]=1;//if we have target is 0, then we can have 1 way to get that ans;
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=target;j++){
//             if(j>=coins[i-1]){
//                 dp[i][j] = dp[i][j-coins[i-1]]%MOD+dp[i-1][j]%MOD;
//             }
//             else{
//                 dp[i][j]= dp[i-1][j]%MOD;
//             }
//             dp[i][j]  %= MOD;
//         }
//     }
//     return dp[n][target];
// }

// int main(){
//     int n,target;
//     cin>>n>>target;
//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     cout<<solve(n,target,coins);
// }



//brute force recursion+memoization
// int solve(int n,int target,vector<int> &coins,vector<vector<int>> &dp){
//     if(target==0) return 1;
//     if(n==0) return 0;

//     if(dp[n][target]!= -1) return dp[n][target];

//     if(target>=coins[n-1]){
//         return solve(n,target-coins[n-1],coins,dp)+solve(n-1,target,coins,dp);
//     }
//     return solve(n-1,target,coins,dp);
// }

// int main(){
//     int n,target;
//     cin>>n>>target;
//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     //here n,target both are changing
//     vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
//     cout<<solve(n,target,coins,dp);
// }

//brute force recursion
// int solve(int n,int target,vector<int> &coins){
//     if(target==0) return 1;
//     if(n==0) return 0;

//     if(target>=coins[n-1]){
//         return solve(n,target-coins[n-1],coins)+solve(n-1,target,coins);
//     }
//     return solve(n-1,target,coins);
// }

// int main(){
//     int n,target;
//     cin>>n>>target;
//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     cout<<solve(n,target,coins);
// }