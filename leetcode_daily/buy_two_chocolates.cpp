#include<bits/stdc++.h>
using namespace std;

//3 2 3 and 0 expected ans is 3 output of below is 0
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        bool zero=false;
        int mx=INT_MIN;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[i]+prices[j]<=money){
                    mx=max(money-prices[i]-prices[j],mx);
                }
            }
        }
        if(mx>=0) {
            return mx;
        }
        return money;
    }
};