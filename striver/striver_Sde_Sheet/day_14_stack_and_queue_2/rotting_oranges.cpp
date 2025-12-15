#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> dir = { {1,0}, {-1,0} , {0,1} , {0,-1} };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }

        int maxTime = 0;

        while(!q.empty()){
            pair<int, pair<int,int>> node = q.front();q.pop();
            int currTime = node.first;
            int currX = node.second.first;
            int currY = node.second.second;
            for(auto it : dir){
                int newX = currX + it.first;
                int newY = currY + it.second;

                if(newX >=0 && newX <n && newY >= 0 && newY < m){
                    if(grid[newX][newY]==1){
                        grid[newX][newY] = 2;
                        maxTime = max(1+currTime, maxTime);
                        q.push({1+currTime , { newX , newY }});
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return maxTime;
    }
};