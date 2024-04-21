#include<bits/stdc++.h>
using namespace std;

//a person can jump one or 2 at a time
//1  ans =0 no need to jump already at stair
//2 ans is 1
//3 stair jump is 2,3 or 3 ans =2
//4 2,3,4 or 2.4 or 3,4 ans = 3
//5


// brute force by recursion
// he is at nth we can move back n-1 or n-2 if nth 0
// n=4 


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.

    //recursion
    long long countWays(int n) {
        if(n==0) return 1;
        if(n<0) return 0;

        return countWays(n-1)+countWays(n-2);
    }
};

