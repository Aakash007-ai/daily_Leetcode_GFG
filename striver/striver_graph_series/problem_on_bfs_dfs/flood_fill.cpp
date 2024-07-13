#include<bits/stdc++.h>
using namespace std;

//so while thinking  x+1 should be bounded code will become x+1<grid.size() it means we can write x+1 anywhere
//so think loud and code according to that


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if(org==color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            auto node = q.front();q.pop();
            
            int x=node.first,y=node.second;
            if(x>0 && image[x-1][y]==org){
                image[x-1][y]=color;
                q.push({x-1,y});
            }

            if(y>0 && image[x][y-1]==org){
                image[x][y-1]=color;
                q.push({x,y-1});
            }

            if(x<image.size()-1 && image[x+1][y]==org){
                image[x+1][y]=color;
                q.push({x+1,y});
            }

            if(y+1<image[0].size() && image[x][y+1]==org){
                image[x][y+1]=color;
                q.push({x,y+1});
            }
        }
        return image;
    }
};