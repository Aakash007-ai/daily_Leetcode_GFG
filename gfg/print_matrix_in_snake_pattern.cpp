#include<bits/stdc++.h>
using namespace std;

class Solution{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix){   
        vector<int> ans;
        bool rtl=true;
        for(auto it:matrix){
            rtl=!rtl;
            if(rtl){
                reverse(it.begin(),it.end());
                //ans.push_back(it.begin(),it.end());
                // copy(it.end(),it.begin(),back_inserter(ans));
                copy(it.begin(),it.end(),back_inserter(ans));
                continue;
                //reverse and push
            }
            copy(it.begin(),it.end(),back_inserter(ans));
            // ans.push_back(it.begin(),it.end());
        }
        return ans;
    }
};