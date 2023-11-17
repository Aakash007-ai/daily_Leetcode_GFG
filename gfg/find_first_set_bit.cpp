#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        if(n==0) return 0;
        int count=1;
        while(n){
            if((n & 1) == 0){
                count++;
                n= n>>1;
            }
            else break;
        }
        return count;
    }
};

