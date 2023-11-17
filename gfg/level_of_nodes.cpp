#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) {
	    if(X==0) return 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> vis(V,0);
        vis[0]=1;
        while(q.empty()){
            auto node=q.front();q.pop();
            for(auto it:adj[node.first]){
                if(it==X) return node.second+1;
                if(!vis[it]){
                    vis[it]++;
                    q.push({it,node.second+1   
                    });
                }
            }
        }
        return -1;
	}
};