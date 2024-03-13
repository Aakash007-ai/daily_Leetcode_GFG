#include<bits/stdc++.h>
using namespace std;

//brute force 
// n=27
// we have 2 digits to remove 2 or 7
//removing 27 -> 20 ,20 -> 18, 18->10 , 10-> 9 , 9->0
// 

int solve(int n){
    //we
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}














































    // vector<int> dp(n+1,1e9);
    // dp[0]=0;
    // for(int i=1;i<=n;i++){
    //     for(char c:to_string(i)){
    //         dp[i]=min(dp[i],dp[i-(c-'0')]+1);
    //     }
    // }
    // cout<<dp[n];