#include<bits/stdc++.h>
using namespace std;

//in bfs we require visited nodes array

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here 
        //v is number of verttices 
        queue<int> q;
        q.push(0);
        vector<int> vis(V,0);
        vis[0]++;
        //so, vertices count is used to create visited array of size of number of vertices
        vector<int> ans;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int src=q.front();q.pop();
                ans.push_back(src);
                for(auto it:adj[src]){
                    if(!vis[it]){
                        vis[it]++;
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};