#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/coin-change2448/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
    nmber of ways to get sum from avaialabe coins
*/
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        if(sum==0) return 1;
        if(N==0) return 0;

        if(sum>=coins[N-1]){
            return count(coins,N,sum-coins[N-1])+count(coins,N-1,sum);
        }
        return count(coins,N-1,sum);
    }
};

int main(){
    int n;cin>>n;
    int sum;cin>>sum;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    Solution obj;
    cout<<obj.count(coins,n,sum);
}