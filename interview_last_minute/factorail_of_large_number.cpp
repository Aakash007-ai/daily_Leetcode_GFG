#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // abc x
  //  (c*x)%10 carry = b+(c*x)/10
    void multiply(vector<int>& multi, int x){
        int carry = 0;
        for(int i=0;i<multi.size();i++){
            int tempMulti = (multi[i]*x)+carry;
            multi[i] = tempMulti%10;
            carry = tempMulti/10;
        }

        while(carry){
            multi.push_back(carry%10);
            carry/=10;
        }
    }
    vector<int> factorial(int n) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=2;i<=n;i++){
            multiply(ans,i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};