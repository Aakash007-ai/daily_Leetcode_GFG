#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/*
    find minimum no. of coins required to make sum, coins are infinte
    if not posiible return -1

    so if sum == 0 return 0 as no coins required
    if we reach at 0 index we can't get sum, return something so we can get ans
*/

class Solution{
	public:
	int minCoins(vector<int> &coins, int n, int sum) {
        if(sum==0) return 0;
        if(n==0) return -1;

        if(sum >= coins[n-1]){
            int pick =minCoins(coins,n,sum-coins[n-1]);
            int notPick = minCoins(coins,n-1,sum);

            if(pick== -1 && notPick==-1) return -1; //we can solve it
            if(pick==-1) return notPick;
            if(notPick == -1) return pick+1;
            return min(pick+1,notPick);
        }

        return minCoins(coins,n-1,sum);
	} 
};

int main(){
    int sum;cin>>sum;
    int n;cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    Solution obj;
    cout<<obj.minCoins(coins,n,sum);
}