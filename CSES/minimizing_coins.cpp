#include <bits/stdc++.h>
using namespace std;

// top-down
int solve(int n, int target, vector<int> &coins)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= target; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (auto it : dp)
    {
        for (auto itr : it)
        {
            cout << itr << " ";
        }
        cout << "\n";
    }

    return dp[n][target];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int ans = solve(n, x, coins);
    if (ans == INT_MAX - 1)
        cout << -1;
    else
        cout << ans;
}

// local
//  #include <bits/stdc++.h>
//  using namespace std;

// once go through video of unbounded knapsack

// target knapsack with unlimited items

// find minimal coins required to get that sum

// recursion
// base case
/*
    if we have target 0 return 0 no coins required to get that sum
    if we are not having coins return but have target return infinity we can't get a some as coins required for this

    if(current coin is less than target){
        we can take that coin and again we can do that or we can skip that coins to take up
    }
    else if target is less than that coin, then we can only skip
*/
// choice diagram
//  int solve(int n,int target,vector<int> &coins){
//      if(target == 0) return 0;//we dont require any caoins to get sum
//      if(n==0) return INT_MAX;

//     if(coins[n-1]<=target){
//         int left=solve(n,target-coins[n-1],coins);
//         int right = solve(n-1,target,coins);
//         if(left == INT_MAX) return right;
//         if(right == INT_MAX) return left+1;
//         return min(left+1,right);
//     }
//     return solve(n-1,target,coins);
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     int ans=solve(n,x,coins);
//     if(ans==INT_MAX) cout<<-1;
//     else cout<<ans;
// }

// memoization
//  int solve(int n,int target,vector<int> &coins,vector<vector<int>> &dp){
//      if(!target) return 0;
//      if(!n) return  INT_MAX;

//     if(dp[n][target]!= -1) return dp[n][target];

//     if(coins[n-1]<=target){
//         int left= solve(n,target-coins[n-1],coins,dp);
//         int right = solve(n-1,target,coins,dp);
//         if(left == INT_MAX) return dp[n][target]=right;
//         if(right == INT_MAX) return dp[n][target]= left+1;
//         return dp[n][target] = min(left+1,right);
//     }

//         return dp[n][target]=solve(n-1,target,coins,dp);
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }
//     vector<vector<int>> dp(n+1,vector<int> (x+1,-1));
//     int ans=solve(n,x,coins,dp);
//     if(ans==INT_MAX) cout<<-1;
//     else cout<<ans;
// }

// // top-down
// int solve(int n, int target, vector<int> &coins){
//     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

//       // if target is 0 for any number of coins we get ans
//     for (int i = 0; i <= n; i++){
//         dp[i][0] = 0;
//     }

//        // if n is 0 for any target we cannot get sum so int max
//     for (int i = 0; i <= target; i++){
//         dp[0][i] = INT_MAX-1;
//     }

//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= target; j++){
//             if (coins[i - 1] <= j){
//                 // int left = dp[i][j - coins[i - 1]];
//                 // int right = dp[i - 1][j];
//                 // if (left == INT_MAX)
//                 //     dp[i][j] = right;
//                 // else if (right == INT_MAX)
//                 //     return dp[i][j] = left + 1;
//                 // else
//                 //     dp[i][j] = min(left + 1, right);
//                 dp[i][j] = min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
//             }
//             else{
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[n][target];
// }

// int main()
// {
//     int n, x;
//     cin >> n >> x;
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> coins[i];
//     }
//     int ans = solve(n, x, coins);
//     if (ans == INT_MAX-1)
//         cout << -1;
//     else
//         cout << ans;
// }