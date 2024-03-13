#include<bits/stdc++.h>
using namespace std;

//check why our program give this ans

int MOD = 1e9+7; //earlier it is int    
//always give resemblence name to variable
//we have a target and at any time we can choose anyone of available coins or by choosing all availble one by one

//recursion
// int solve(int n,int target,vector<int> &coins){
//     if(target==0) return 1;// if target become 0  we have to return ans
//     //what if we don't have coin to makeit loose e.g. we have target 1 and coins 2,3
//     int count=0;
//     for(int i=0;i<coins.size();i++){
//         if(target>=coins[i]){//we have a coin whose value is greater
//             count+=solve(n,target-coins[i],coins);
//         }
//     }
//     return count;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<solve(n,x,arr);
// }


// //memoization
// //here we observe only target is changing
// int solve(int n,int target,vector<int> &coins,vector<int> &dp){
//     if(target==0) return 1;// if target become 0  we have to return ans
//     //what if we don't have coin to makeit loose e.g. we have target 1 and coins 2,3
//     if(dp[target] != -1 ) return dp[target];
//     int count=0;
//     for(int i=0;i<coins.size();i++){
//         if(target>=coins[i]){//we have a coin whose value is greater
//             count+= solve(n,target-coins[i],coins,dp)%MOD;
//         }
//     }
//     return dp[target]=count%MOD;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int> dp(x+1,-1);
//     cout<<solve(n,x,arr,dp);
// }


// //top down
// // dp[i] means no. of ways to get sum i
// // so according to base case when i == 0 we have 1 ways
// int solve(int n,int target,vector<int> &coins){
//     vector<int> dp(target+1,0);
//     dp[0]=1;

//     for(int j=1;j<=target;j++){
//         for(auto it : coins){
//             if(j>=it){
//                 dp[j] += dp[j-it]%MOD;
//                 dp[j] %=MOD;//dp will get overflow we have to reduce it as soon as possible
//             }
//         }
//         // dp[j] %=MOD;
        
//     }
//     return dp[target];
// }



// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<solve(n,x,arr);
// }





 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //meaning of above lines
    //if we don't use these lines then we have to use endl instead of "\n"
    //and we have to use fflush(stdout) after cout
    //and we have to use cin.tie(NULL) and cout.tie(NULL) to avoid flushing of buffer

 
   long long int c,n,x;
    cin>>n>>x;
    
    int mod = 1e9+7;
    
    vector<long long int> coins;
    
    for(int i=0;i<n;i++)
    {
        cin>>c;
        coins.push_back(c);
    }
    
    vector<long long int> dp(x+1,0);
    dp[0]=1;
    
    for(long long int i=1;i<=x;i++)
    {
        //dp[i]=INT_MAX;
        for(long long int j=0;j<n;j++)
        {
            if(i-coins[j] >= 0)
            dp[i] += dp[i-coins[j]];
            dp[i] %= mod;
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}