#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int src,vector<int> adj[],vector<int> &ans, vector<int> &visited){
        visited[src]++;
        ans.push_back(src);
        for(auto it:adj[src]){
            if(!visited[it]){
                dfs(it,adj,ans,visited);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> visited(V);//creat a vector with 0;
        dfs(0,adj,ans,visited);
        return ans;
    }
};