#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
    s1-s2=d how how many condition can be formed
    s1+s2 = s
    2s1 = d+s
    s1=d+s/2
*/
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sumAll = accumulate(arr.begin(),arr.end(),0);
        int netSum = sumAll+d;
        if(netSum%2) -1; //if it is odd the we can't have such subset
        int target= netSum/2;

        vector<vector<int>> dp(n+1,vector<int> (target+1));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(j>=arr[i-1]){
                    dp[i][j]= dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};

int main(){
    int n;cin>>n;
      int d;cin>>d;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  
    Solution obj;
    cout<<obj.countPartitions(n,d,arr);
}