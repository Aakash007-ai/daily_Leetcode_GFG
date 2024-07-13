#include<bits/stdc++.h>
using namespace std;

/*
    tag - detect cycle in directed graph
    so we can pick a next course if all its prerequestie course get completed
    so putting only those courses whose indegree become 0, means we have covered all its prerequestie

*/

//may get failed when they are single nodes but prerequesties does not follow input
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