#include<bits/stdc++.h>
using namespace std;

class Solution {
    using PII = pair<int,int>;
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> g(n);
        for(auto& e : edges){
            int x = e[0], y= e[1], z=e[2];
            g[x].emplace_back(y,z);
            g[y].emplace_back(x,2*z);
        }

        
        vector<int> d(n,INT_MAX);
        vector<bool> v(n,false);
        priority_queue<PII, vector<PII> , greater<PII>> pq;
        d[0] = 0;
        pq.emplace(0,0);

         while(pq.empty()){
            int x = pq.top().second;
            pq.pop();

            if(x == n-1){
                return d[x];
            }

            if(v[x]) continue;
            v[x] = 1;
            for(auto& [y,w] : g[x]){
                if(d[x]+w<d[y]){
                    d[y] = d[x]+w;
                    pq.emplace(d[y],y);
                }
            }
        }
        return -1;
    }
};