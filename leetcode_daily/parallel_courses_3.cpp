#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);//n is from 1
        vector<int> indeg(n,0);
        for(auto it:relations){
            adj[it.front()].push_back(it.back());
            indeg[it.back()]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i+1);
            }
        }
        printf("queeue successfully taken %d",q.size());
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int mxTime=0;
            for(int i=0;i<n;i++){
                int node = q.front();q.pop();
                mxTime=max(mxTime,time[node-1]);
                for(auto itr:adj[node]){
                    indeg[itr-1]--;
                    if(!indeg[itr-1]) q.push(itr);
                }
            }
            ans+=mxTime;
        }
        return ans;
    }
};



int main(){
    int n;cin>>n;
    vector<vector<int>> relations;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        relations.push_back({x,y});
    }
    cout<<"relations created\n";
    vector<int> time;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        time.push_back(x);
    }
    cout<<"input taken";
    Solution obj;
    cout<<obj.minimumTime(n,relations,time);
}