#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMax(n);
        prefixMax[n-1] = prices[n-1];
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            prefixMax[i] = max(prices[i],prefixMax[i+1]);
        }

        for(int i=0;i<n;i++){
            ans = max(ans, prefixMax[i]-prices[i]);
        }
        return ans;
    }
};