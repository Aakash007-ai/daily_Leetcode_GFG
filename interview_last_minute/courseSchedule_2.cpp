#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<int> adj[numCourses];

        for(auto it:prerequisites){
            int s = it.front();
            int f = it.back();
            adj[f].push_back(s);
            indeg[s]++;
        }

        queue<int> q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int n = q.front();q.pop();
            ans.push_back(n);
            for(auto it: adj[n]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};