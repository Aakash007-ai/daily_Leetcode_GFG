#include<bits/stdc++.h>
using namespace std;

/** 
 * while reading question create a mindmap of question in mind , a little story verse of question
*/

class Solution {
public:
    bool bfs(int src,vector<vector<int>> &graph, vector<int> &colorNode){
        queue<int> q;
        colorNode[src]=1;
        q.push(src);

        while(!q.empty()){
            int n = q.front();q.pop();
            int col = colorNode[n];

            for(auto it: graph[n]){
                if(colorNode[it] == -1){
                    colorNode[it] = !col;
                    q.push(it);
                }else if(colorNode[it] == col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int numNodes = graph.size();
        vector<int> colorNode (numNodes,-1);
        for(int i=0;i<numNodes;i++){
            if(colorNode[0]==-1){
                if(!bfs(i, graph, colorNode)) return false;
            }
        }
        return true;
    }
};