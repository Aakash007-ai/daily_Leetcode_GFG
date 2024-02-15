#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void dfs(vector<int> adj[],int src,vector<int> &vis){
        vis[src]++;
        ans.push_back(src);
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(adj,it,vis);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);//all nodes are not visited yet
        dfs(adj,0,vis);
        return ans;
    }
};