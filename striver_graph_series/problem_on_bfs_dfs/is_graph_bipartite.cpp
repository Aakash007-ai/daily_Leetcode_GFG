#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>> &graph,int src,vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src]++;
        vector<int> color(graph.size(),-1);
        color[src]=0;
        while(!q.empty()){
            auto ele=q.front();q.pop();
            int node= ele.first;
            int nodeColor=ele.second;
            for(auto it:graph[node]){
                if(!vis[it]){
                    //mark as visited and put in queue with color also fill color 
                    vis[it]++;
                    color[it]=!nodeColor;
                    q.push({it,color[it]});
                }
                else{
                    if(nodeColor != color[it]) return false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();//we have n no. of nodes
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i] && !bfs(graph,i,vis))
    }
    return true;
    }
};