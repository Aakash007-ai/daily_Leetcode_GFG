#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> list(V);
        for(auto it:edges){
            list[it.first].push_back(it.second);
            list[it.second].push_back(it.first);
        }

        return list;
    }
};
