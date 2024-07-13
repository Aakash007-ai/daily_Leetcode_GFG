#include<bits/stdc++.h>
using namespace std;
/*
    topological Sort
    start with 0 indegree and travers next if all its all parent visit it and its indeg become 0
    int this way we move from all source to mid element located in web
*/
// we have vertices lable from 0
class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
        vector<int> indeg(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        vector<int> ans; 
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

       
        while(!q.empty()){
            int node= q.front();q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
	}
};