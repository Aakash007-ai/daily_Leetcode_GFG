#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j=0,k=0;
        for(int i=1;i<=n;i++){
            if(j>=target.size()) break;

            if(i==target[j]){
                ans.push_back("Push");
            }else{
                while(i!=target[j]){
                    ans.push_back("Push");
                    i++;k++;
                }
                while(k--){
                    ans.push_back("Pop");
                }
                ans.push_back("Push");
            }
            j++;
        }
        return ans;
    }
};