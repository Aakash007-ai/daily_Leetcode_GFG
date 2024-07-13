#include<bits/stdc++.h>
using namespace std;

//here we can't use dp as in future a value can be 0 but we are calculating from start
//so we use dfs from every non 0 value and return the minimium distance
//in bfs we can'tgo back 
//so it is best suited for dfs

//******************************************************** but the heck is we can do one more from backwards

// class Solution {
// public:
//      int dfs(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dis){
//         if(dis[i][j]==0) return 0;
//         if(dis[i][j]!=INT_MAX) return dis[i][j];

//         int up=INT_MAX,down=INT_MAX,left=INT_MAX,right=INT_MAX;

//         if(i>0){
//             up=dfs(i-1,j,mat,dis);
//         }
//         if(i+1<mat.size()){
//             down=dfs(i+1,j,mat,dis);
//         }

//         if(j>0){
//             left=dfs(i,j-1,mat,dis);
//         }

//         if(j+1<mat[0].size()){
//             right=dfs(i,j+1,mat,dis);
//         }
        
//         int mn=min({up,down,left,right});
//         dis[i][j]= mn==INT_MAX? INT_MAX : mn+1;

//         return dis[i][j];
//     }

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         //so for every 1 we traverse and find minimum
//         vector<vector<int>> dis(mat.size(),vector<int> (mat[0].size(),INT_MAX));//-1 means distance is not calculated yet

//         bool singleZero=false;
//         for(int i=0;i<mat.size();i++){
//             for(int j=0;j<mat[0].size();j++){
//                 if(!mat[i][j]){
//                     dis[i][j]=0;
//                     singleZero=true;
//                 }
//             }
//         }

//         if(singleZero)

//         for(int i=0;i<mat.size();i++){
//             for(int j=0;j<mat[0].size();j++){
//                 if(mat[i][j]==1){
//                     //traverse and find min distance
//                     dfs(i,j,mat,dis);
//                 }
//             }
//         }
//         return dis;
//     }
// };


//                              forward and backward

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col, INT_MAX - 100000)); // Initialize ans with large values
        
        // Forward pass
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                } else {
                    if (i > 0) ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                    if (j > 0) ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                }
            }
        }
        
        // Backward pass
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (i < row - 1) ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                if (j < col - 1) ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
            }
        }
        return ans;
    }
};