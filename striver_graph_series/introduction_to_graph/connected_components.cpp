#include<bits/stdc++.h>
using namespace std;

//try this with union find data structure

void dfs(vector<vector<int>> &roads, int src,vector<int> &vis){
    vis[src]=1;
    for(int i=0;i<roads[src].size();i++){//from current source to which destination we can move which are not currently visited
        if(i!=src && roads[src][i] && !vis[i]){
                dfs(roads,i,vis);
        } 
    } 
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    int count=0;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(roads,i,vis);
        }
    }
    return count;
}

