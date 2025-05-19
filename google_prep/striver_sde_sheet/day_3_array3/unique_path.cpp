#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        //using DP 
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m,vector<int>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
            return dp[m-1][n-1];
        }

        //using combinatories
        //since he will move m-1 down and n-1 right, he will make m+n-2 moves
        // and we just have to either choose combination of m-1 down or n-1 right

        // formula = (m+n-2)!/(m-1)!(n-1)! == m+n-2 C m-1 or m+n-2 C n-1
        // 1 * 2 * 3 * ... * (m+n-2) / (1 * 2 * 3 * ... * (m-1) * 1 * 2 * 3 * ... * (n-1))
        // delete max elements so we can get the min elements to compute
        // NCr = 1*2*3*...*(N) / 1*2*3*...(r) *(1*2*3*...(N-r))
        // Ncr = N-r+1 * N-r+2 * N-r+3 * ... * N / 1*2*3*...(r)
        int uniquePaths(int m,int n){
            int N = m+n-2;
            int r = min(m-1,n-1);

            double ans = 1;
            for(int i=0;i<r;i++){
                // ans *= (N-i);
                // ans /= (i+1);
                ans = ans * (N-i) / (i+1);
            }
            return (int)ans;
        }
    };