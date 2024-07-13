#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src,vector<vector<int>> &isConnected, vector<int> &visited){
        visited[src]++;
        for(int i=0;i<visited.size();i++){
            if(i!= src && !visited[i] && isConnected[i][src]){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //we have isConnected a 2d matrix of size nxn representing num of nodes
        //we have adjacency matrix
        int n=isConnected.size();//number of nodes
        vector<int> visited(n);
        int numOfProvince=0;
        //since src is not given we have assume every node as src and traverse if it is not visited
        for(int i=0;i<n;i++){
            if(!visited[i]){
                numOfProvince++;
                dfs(i,isConnected,visited);
            }
        }
        return numOfProvince;        
    }
};