#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
     vector<int> bfsOfGraph(int V, vector<int> adj[]) {//directed graph given
        // Code here
        // always src=0
        queue<int> q;
        q.push(0);
        vector<int> ans;
        vector<int> visited(V,0);
        visited[0]++;
        while(!q.empty()){
            int n=q.front();q.pop();
            ans.push_back(n);
            for(auto it:adj[n]){
                if(!visited[it]){
                    visited[it]++;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
