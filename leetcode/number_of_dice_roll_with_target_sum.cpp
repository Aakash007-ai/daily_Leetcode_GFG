#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if(n==0) return target==n;
        if(k==0) return 0;

        if(k > target){
            return numRollsToTarget(n,k-1,target);
        }

        return numRollsToTarget(n-1,k,target-k)+numRollsToTarget(n,k-1,target);
    }
};