#include<bits/stdc++.h>
using namespace std;
// try another apprach too
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
/*
    this time we need to find minimum difference of subset sum
    e.g s1-s2 = minimum  nearest to 0
    s = s1+s2
    ans + s = 2s1
    ans = 2s1-sum of all
    or 
    abs(ans) = abs(s - 2s1) or abs(2s1-sum)
    we just need to find a subset sum whose (2s1-summ) is min
    so we have a choice of taking subset sum
    so we know s2 is between 0 and sum of s1
    so find all valid subset fact is that they all get generated automatically if target sum is range
*/
class Solution{
  public:
  void printVector(vector<vector<bool>> v){
    for(int i=0;i<v.size();i++){
       cout<<i; 
        for(int j=0;j<v[0].size();j++){
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
  }
	int minDifference(int arr[], int n)  { 
        if(n==1) return arr[0]; 
        int range= accumulate(arr,arr+n,0);
        vector<vector<bool>> dp(n+1,vector<bool> (range+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=range;j++){
                if(j>=arr[i-1]){
                    dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<int> subset;
        for(int i=1;i<=range/2;i++){
            if(dp[n][i]){
                subset.push_back(i); //these subset are valid
            }
        }
        int mn=INT_MAX;
        for(auto it:subset){
            mn = min(mn,abs(range-2*it));
        }
        return mn;
	} 
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.minDifference(arr,n);
}

//  int solve(int wt[], int n , int total , int s2,vector<vector<int>> &t){
//           // Your code here
//       if(n==0)return t[n][s2]=abs(2*s2 - total);
//       if (t[n][s2]!=-1) return  t[n][s2];
//       return t[n][s2] = min(solve(wt,n-1,total,s2+wt[n-1],t), solve(wt,n-1,total,s2,t));    }

//     int minDifference(int arr[], int n)  { 
//         // Your code goes here
//         int sum = 0;
//         for(int i=0;i<n;i++)sum+=arr[i];
//         //cout<<sum;
//         vector<vector<int>> t(n+1,vector<int>(sum+1, -1));
//         return solve(arr,n ,sum,0,t);  
//     }
