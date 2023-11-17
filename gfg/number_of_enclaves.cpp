#include<bits/stdc++.h>
using namespace std;


// 6 6
// 0 0 0 0 0 0
// 0 0 1 0 1 0
// 0 1 0 1 1 0
// 0 1 1 1 1 0
// 0 1 1 1 1 0
// 0 0 0 1 0 0
// Your Code's output is: 
// 5
// It's Correct output is: 
// 1

class Solution {
    private:
    void dfs(vector<vector<int>> &grid,int i,int j){
        grid[i][j]=0;
        if(i>0 && grid[i-1][j]) dfs(grid,i-1,j);
        if(i<grid.size()-1 && grid[i+1][j]) dfs(grid,i+1,j);
        if(j>0 && grid[i][j-1]) dfs(grid,i,j-1);
        if(j<grid[0].size()-1 && grid[i][j+1]) dfs(grid,i,j+1);
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();

        //first traverse top row then right, bottom, left 
        for(int j=0;j<m;j++){
            if(grid[0][j]) dfs(grid,0,j);
            if(grid[n-1][j]) dfs(grid,n-1,j);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]) dfs(grid,i,0);
            if(grid[i][m-1]) dfs(grid,i,m-1);
        }

        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            ans +=accumulate(grid[i].begin(),grid[i].end(),count);
        }
        return ans;
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    Solution obj;
    cout<<obj.numberOfEnclaves(grid);
}