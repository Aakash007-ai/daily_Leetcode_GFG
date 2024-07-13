#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
//     }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==1) return {0};
        vector<int> indeg(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        //vector<int> vis(numCourses,0);
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            //vis[node]=1;
            for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it]==0) q.push(it);
            }
        }
        return ans.size()==numCourses?ans:vector<int> {};
    }
};