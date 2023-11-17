#include<bits/stdc++.h>
using namespace std;
//  how many subsets equal to sum
/*
    if we have array that has some elements n>0
    then check nth if it is less than sum then we have option to choose or not to choose
    solve(n-1,v,sum-vector[n-1]) + solve(n-1,v,sum)
    if value[n]>sum then solve(n-1,v,sum)

    hit condition if(sum==0) return 1;
    if(n==0) return 0;

*/

/*
    after getting ans from basic recursion now memoizing it
    
    we have to store that recursion which are already calculated
    so, find the state varaiable here they are n and sum, in some case for same n and sum we have to find recursion again
    so we store that 
*/

class Solution{
	public:
    //memoizing recursion
    int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        return dp[n][sum]=helper(arr,n,sum,dp);
	}
    //failed at 
    // 10 31
    // 9 7 0 3 9 8 6 5 7 6
    int helper(int v[], int n, int sum,vector<vector<int>> dp)
	{       
        if(sum==0) return 1;
        if(n==0) return 0;
        if(dp[n][sum] != 0) return dp[n][sum];

        if(v[n-1]>sum){
            return dp[n][sum]=helper(v,n-1,sum,dp);
        }
        int temp=sum-v[n-1];
        return dp[n][sum]=helper(v,n-1,temp,dp)+helper(v,n-1,sum,dp);    
    }
    

    // using recursion 
	// int perfectSum(int v[], int n, int sum)
	// {      
    //     if(sum==0) return 1;
    //     if(n==0) return 0;

    //     if(v[n-1]>sum){
    //         return perfectSum(v,n-1,sum);
    //     }
    //     int temp=sum-v[n-1];
    //     int left=perfectSum(v,n-1,temp);
    //     int right=perfectSum(v,n-1,sum);
    //     return left+right; 
    // }
};

int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution obj;
    cout<<obj.perfectSum(a,n,sum)<<"\n";
    return 0;
}