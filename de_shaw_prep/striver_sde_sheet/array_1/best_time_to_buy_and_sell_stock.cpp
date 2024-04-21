#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minArr;
        int ans=0;
        int minPrice=prices[0];
        for(int i=1;i<prices.size();i++){
            minPrice=min(prices[i-1],minPrice);//we got the min preice from rest of element
            //now calculate profit if it is there
            if(minPrice<prices[i]){
                ans=max(ans,prices[i]-minPrice);
            }
        }
        return ans;
    }
};