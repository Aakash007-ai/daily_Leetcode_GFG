#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> ans;
     void solve(int i,int n,vector<int> &num,int t,vector<int> &ds,int sum){
            if(sum>t) return;
            if(sum==t){
                ans.emplace_back(ds);
                return;
            }
            if(i==n) return;

            sum+=num[i];
            ds.push_back(num[i]);
            
            solve(i,n,num,t,ds,sum);
            sum-=num[i];
            ds.pop_back();
            solve(i+1,n,num,t,ds,sum); //to print array
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> ds;
            int sum=0;
            solve(0,candidates.size(),candidates,target,ds,sum);
            return ans;
        }
    };