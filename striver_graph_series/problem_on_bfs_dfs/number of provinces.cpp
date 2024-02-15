#include<bits/stdc++.h>
using namespace std;


//adjacency matrix


class Solution {
public:
    void dfs(vector<vector<int>> & adjMat,int src, vector<int> & vis){
        vis[src]++;
        for(int i=0;i<adjMat[src].size();i++){
            if(i != src && adjMat[src][i] && !vis[i]){
                dfs(adjMat,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); //here we got number of nodes 
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected,i,vis);
            }
        }
        return ans;
    }
};

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;//expected o/p is 2
    cout << ob.findCircleNum(adj) << endl;
        
    return 0;
}