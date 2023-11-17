#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy){
            if(t==1) return false;
            return true;
        }
        int r=max(fy,sy)-min(fy,sy);
        int c=max(fx,sx)-min(fx,sx);
        //just find minimum time max can be stretched as long as we want
        int mn=min(r,c) + max(r,c)-min(r,c);
        if(t<mn) return false;
        return true;
    }
};