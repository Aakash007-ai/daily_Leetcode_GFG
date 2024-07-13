#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        vector<int> adj[numCourses];

        for(auto it:prerequisites){
            adj[it.back()].push_back(it.front());
            indeg[it.front()]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){//picking the initial course
            if(indeg[i]==0){
                q.push(i); //the first course to pick
            }
        }

        if(q.empty()) return false; // no starting point return false;

        while(!q.empty()){
            int node=q.front();q.pop();

            for(auto it:adj[node]){
                indeg[it]--;
                if(!indeg[it]){
                    q.push(it);
                }
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indeg[i]!=0) return false;
        }

        return true;
    }
};