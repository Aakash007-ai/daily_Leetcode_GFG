#include<bits/stdc++.h>
using namespace std;


// 4
// ....
// .*..
// ...*
// *...
//

// 1 1 1 1
// 1 0 1 2
// 1 1 2 0
// 0 1 3 3

int MOD=1e9+7;

int solve(vector<string> grid,int n){
    vector<vector<int>> dp(n,vector<int> (n,0));
    
    for(int i=0;i<n;i++){//lets's travesr first path
        if(i==0){
            if(grid[i][i]=='.') dp[0][0]=1;
            else dp[i][i]=0;
            continue;
        }
        

        if(grid[0][i]=='.') dp[0][i]=dp[0][i-1];
        else dp[0][i]=0;

        if(grid[i][0]=='.') dp[i][0]=dp[i-1][0];
        else grid[i][0]=0;
    }

    //filled the first row and column
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='.') dp[i][j]=dp[i-1][j]%MOD+dp[i][j-1]%MOD;
            else dp[i][j]=0;

            dp[i][j] %=MOD;
        }
    }
    return dp[n-1][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    cout<<solve(grid,n);

}