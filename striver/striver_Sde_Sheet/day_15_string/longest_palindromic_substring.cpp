#include<bits/stdc++.h>
using namespace std;


//this algo fails  for for test cases
// "aacabdkacaa" 
//  aacakdbacaa reverse ,as we are not matching palindromic condition when string match
//  dp[i][j] means palindrom string of length ending at i-1, so starting of palindrom s[i-dp[i,j]] to s[i-1]
//  in reversed it is s[n-j(index from end or elements from end)]

/**
 * Condition: i - dp[i][j] == n - j

Now, this is the magic:

i - dp[i][j] = start index of substring in s

n - j = start index of substring in s (mirrored from reverse string)

If both are equal,
that means the substring in s and its mirrored substring in reverse(s)
are actually the same substring in original string.

Thus → palindrome confirmed!

 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string b = s;
        reverse(b.begin(), b.end());
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       int maxLen = INT_MIN;
       pair<int,int> maxIdx = {-1,-1};
       for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                if(dp[i][j]>maxLen){
                    maxLen = dp[i][j];
                    maxIdx = make_pair(i,j);
                }
            }
        }}

        int i=maxIdx.first, j=maxIdx.second;
        string res = "";
        while(maxLen){
            if(dp[i][j] == maxLen) res.push_back(s[i-1]);
            i--;j--;maxLen--;
        }
        return res;
    }
};

// first find lcs longest common subsequence using recursion
// first find length

class Solution { //working solution
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string b = s;
        reverse(b.begin(), b.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxLen = 0, endIdx = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;

                    // Ensure palindrome alignment
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

        return s.substr(endIdx - maxLen + 1, maxLen);
    }
};
