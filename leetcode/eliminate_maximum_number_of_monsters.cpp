#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> mh;
        int n=dist.size();
        for(int i=0;i<n;i++){
            int axis = dist[i]-(speed[i]*n);
            mh.push({axis,speed[i]});
        }
        int ans=0;
        while(n){
            auto tp=mh.top();mh.pop();
            if(tp.first + tp.second*n >0 ) ans++;
            else break;
            n--;
        }
        return ans;
    }
};