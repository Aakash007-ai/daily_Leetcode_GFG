#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
    }
    vector<vector<int>> LCSDp; // x+1, y+1 size
    int lcs(int i, int j, string x, string y){
        if(i == 0 || j == 0){
            return 0;
        }
        if(x[i-1] == y[j-1]){
            return lcs(i+1,j+1, x,y);
        }

        return min(lcs(i+1,j,x,y), lcs(i,j+1,x,y));
    }

    int lcs(string x){
        int n = x.size();
        string y = x; // n=8
        // abccba i  4 (n-j) 8-6 = 2 
        // abccba j  6
        reverse(y.begin(), y.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        int maxLen = INT_MIN, endIdx = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;i++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1; 

                     int revIdx = n - j; // corresponding index in original string
                    if (revIdx + dp[i][j] - 1 == i - 1) {
                        if (dp[i][j] > maxLen) {
                            maxLen = dp[i][j];
                            endIdx = i - 1;
                        }
                    }
                }
            }
        }
    }
};