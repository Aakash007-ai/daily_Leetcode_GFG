#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool comp(vector<int> a, vector<int> b){
        if(a.front()<b.front()) return true;
        if(a.front()==b.front()) return a.back()<b.back();
        return false;
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int mx=INT_MIN;
        for(int i=1;i<points.size();i++){
            mx=max(mx,points[i][0]-points[i-2][0]);
        }
        return mx;
    }
};

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        
        return ans;
    }