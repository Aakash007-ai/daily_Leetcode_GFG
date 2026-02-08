#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<vector<int>> adj;
    // vector<vector<int>> revAdj;
    // map<pair<int,int>,int> dp;
    // vector<bool> visited;

    // int dfs(int src, int parent){
    //     int ans = 0;
    //     visited[src] = true;

    //     // if(dp.find({src,parent}) != dp.end()){
    //     //     return dp[{src,parent}];
    //     // }

    //     for(auto it: adj[src]){
    //         if(it != parent && !visited[it]) ans += dfs(it,src);
    //     }

    //     for(auto it:revAdj[src]){
    //         if(it != parent && !visited[it]) ans += dfs(it,src)+1; 
    //     }

    //     return ans;
    //     // return dp[{src,parent}] = ans;
    // }

    // // int bfs(int src, int parent){

    // // }

    // vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    //     adj = vector<vector<int>>(n);
    //     revAdj = vector<vector<int>>(n);
    //     dp.clear();

    //     for(auto it: edges){
    //         adj[it.front()].push_back(it.back());
    //         revAdj[it.back()].push_back(it.front());
    //     }

    //     vector<int> ans;

    //     for(int i=0;i<n;i++){
    //         visited.clear();
    //         visited = vector<bool>(n);
    //         // visited[i] = true;
    //         ans.push_back(dfs(i,-1));
    //     }

    //     return ans;
    // }

    //Rerooting DP
    vector<vector<pair<int,int>>> graph;
    vector<int> ans;

    int dfs1(int node, int parent){
        int cost = 0;
        for(auto [v,w]:graph[node]){
            if(v == parent){
                continue;
            }
            cost += w + dfs1(v,node);
        }
        return cost;
    }

    void dfs2(int u, int p){
        for(auto [v,w] : graph[u]){
            if(v == p){
                continue;
            }

            ans[v] = ans[u] + (w == 0) ? 1: -1;
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges){
        graph.assign(n,{});
        ans.assign(n,0);

        for(auto it:edges){
            graph[it.front()].push_back({it.back(),0});
            graph[it.back()].push_back({it.front(),1});
        }

        ans[0] = dfs1(0,-1);
        dfs2(0,-1);

        return ans;
    }
};