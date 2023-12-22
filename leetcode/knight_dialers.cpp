
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int dp(int remain, int square) {
        if (remain == 0) {//if we are out of jump return 0
            return 1;
        }
        
        if (memo[remain][square] != 0) {//if we have already visited that combination ,, no. of jumps remaining and current square
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {//from curreent square we can jump to
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;//now jump to left jumps, with next position
        }
        
        memo[remain][square] = ans;//memoizinf jump from to which square
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;//n is nuber of jumps we can perform
        memo = vector(n + 1, vector(10, 0)); //dp rule changing elements n and 
        int ans = 0;//intiailly no jumps
        for (int square = 0; square < 10; square++) {//initially we can start from any square
            ans = (ans + dp(n - 1, square)) % MOD;//calculating ans from every square
            //ans is ans + jump dp(n-1,from current position)
        }
        
        return ans;
    }
};