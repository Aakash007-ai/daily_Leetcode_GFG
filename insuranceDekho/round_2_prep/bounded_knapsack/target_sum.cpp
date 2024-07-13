#include<bits/stdc++.h>
using namespace std;
//if you though you find a hard way or the way is not seeing correct
//once think in different way
// https://www.geeksforgeeks.org/problems/target-sum-1626326450/1
/*  either just do a recursion 
    assign symbols +/- such that we got target sum
    or if we stay and think
    s1-s2=target
    s1+s2=s
    2s1 = s+target
    we can solve this way too
*/


class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
      if(n==0 && target==0) return 1;
      if(n==0 && target !=0) return 0;

      return findTargetSumWays(n-1,A,target + A[n-1])+ findTargetSumWays(n-1,A,target -1*A[n-1]);   
    }
};


int main(){
    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;cin>>d;
    Solution obj;
    cout<<obj.findTargetSumWays(n,arr,d);
    // return 0;
}