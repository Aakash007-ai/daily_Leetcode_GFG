#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // first create a proper adjacency list, here it is directed graph
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses);
        for(auto it: prerequisites){
            adj[it.back()].push_back(it.front());
            indeg[it.front()]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        if(q.size()==numCourses) return true;

        while(!q.empty()){
            int n = q.front();q.pop();
            for(auto it: adj[n]){
                indeg[it]--;
                if(indeg[it]== 0){
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