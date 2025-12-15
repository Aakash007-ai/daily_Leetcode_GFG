#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &ans){
        // if(vis[src]) return;
        vis[src] = 1;
        ans.push_back(src);

        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(it, adj, vis, ans);
            }
        }
    }

    void bfs(int src, vector<int> adj[],vector<int> &vis, vector<int>& ans){
        vis[src]=1;
        ans.push_back(src);
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //dfs of graph, we go in depth, we have V vertices
        vector<int> vis(V);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }
        return ans;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(i,adj, vis,ans);
            }
        }
        return ans;
    }
};
