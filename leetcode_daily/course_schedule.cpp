#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        //code here
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(auto it:prerequisites){
            adj[it.front()].push_back(it.back());
            indeg[it.back()]++;
        }

        queue<int> q;
        //even the graph is disconnected we have picked it
        for(int i=0;i<n;i++){//we got node with starting src having indeg 0
            if(indeg[i]==0){
                // cout<<i<<" ";
                q.push(i);
            }
        }
        

        vector<int> ans; //just to get a count
        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
            cout<<"node value is "<<node<<" and n is"<<n<<endl;;
            n--;
            cout<<"after decrement n value n "<<n<<endl;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        for(int i=0;i<n;i++){
            if(indeg[i]!=0) return {};
        }
        cout<<"returning ans";
        return ans;
    }
};


int check(int v,vector<int> &res,vector<int> adj[]){
    vector<int> map(v,-1);
    for(int i=0;i<v;i++){
        map[res[i]]=i;
    }
    for(int i=0;i<v;i++){
        for(int v:adj[i]){
            if(map[i]>map[v]) return 0;
        }
    }
    return 1;
}

int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    vector<vector<int>> prerequesties;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        prerequesties.push_back({u,v});
    }

    vector<int> adj[n];
    for(auto pre:prerequesties){
        adj[pre[1]].push_back(pre[0]);
    }

    Solution obj;
    vector<int> res = obj.findOrder(n,m,prerequesties);
    if(!res.size()) cout<<"No ordering possible"<<endl;
    cout<<check(n,res,adj)<<endl;
}