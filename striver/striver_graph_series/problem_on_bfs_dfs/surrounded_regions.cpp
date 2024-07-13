#include<bits/stdc++.h>
using namespace std;

/*
    capturing all regions that are  4 - directionally surrounded by 'x'
    one point whatever is on boundary other than x is never gonna be surrounded by x
    so we pick all boundary point other than x and mark them something else and traverse with dfs and convert them to other variable
    then do a traversal if other than that character makr it as x

    so we are given that char is always 'X' OR 'O'
*/

class Solution {
public:
    void dfs(int i,int j,char src,char dst,vector<vector<char>> &board){
        board[i][j]=dst;
        if(i>0 && board[i-1][j]=='O') dfs(i-1,j,src,dst,board);
        if(i+1<board.size() && board[i+1][j=='O']) dfs(i+1,j,src,dst,board);
        if(j>0 && board[i][j-1]=='O') dfs(i,j-1,src,dst,board);
        if(j+1<board[0].size() && board[i][j+1]=='O') dfs(i,j+1,src,dst,board);
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        //iterating rowise we search on on first asnd last column
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,'X','Y',board);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,'X','Y',board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,'X','Y',board);
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,'X','Y',board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};