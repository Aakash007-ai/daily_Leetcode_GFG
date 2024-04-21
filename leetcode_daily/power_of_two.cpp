#include<bits/stdc++.h>
using namespace std;

//check whether it is power of 2 or not
//brute force power of 2 means 1 0 0 0 0
// 1 yes 2^0
// 10 yes 2^1
// 100 yes 2^2
// 1000 yes 2^3
// 10000 yes 2^4

// if 0111111 1 less than power of 2
// if 1000000 0 more than power of 2 both & == 0

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        return !(n&(n-1));
    }
};