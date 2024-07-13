#include<bits/stdc++.h>
using namespace std;

//  runtime error 
//  in this question when we are not moving to another cell y+1 so it gives us memory overflow

//multi source bfs and level order 
/*
    directions
    up x-1, y  down x+1,y left x,y-1, right x,y+1
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int level = -1;
        //we have all rotten oranges
        while(!q.empty()){
            //until queue is not empty we traverse 
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){//up down left right
                //get neighbour and mark them rotten 
                auto node= q.front();q.pop();
                int x=node.first,y=node.second;
                if(x>0 && grid[x-1][y]==1){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(x<grid.size()-1 && grid[x+1][y]==1){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(y>0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                if(y<grid[0].size()-1 && grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
            }
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return level==-1 ? 0 : level;
    }
};