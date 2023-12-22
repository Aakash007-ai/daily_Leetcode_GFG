#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     int sumOfDependencies(vector<int> adj[], int V) {
//         // code here
//         int count=0;
//         for(auto it:adj){
//             count++;
//         }
//     }
// };


class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        // code here
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
        
            for(int V:adj[i]){
                printf(" %d ",adj[i][1]);
                indegree[i]++;
            }
        }
        int sum=0;
        for(int i=0;i<indegree.size();i++){
            sum+=indegree[i];
        }
        return sum;
    }
};

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<int> v[n];
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    Solution ob;
    cout<<ob.sumOfDependencies(v,n);
}