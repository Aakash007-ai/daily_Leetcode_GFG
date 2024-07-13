#include<bits/stdc++.h>
using namespace std;


// we have to find maximum sum of i*arr[i] given array can be rotated cloclwise or anticloclwise
class Solution {
 public:
 long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0,maxsum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            maxsum+=long(i)*a[i];
        }
        long long msum=maxsum;
        for(int i=1;i<n;i++)
        {
            maxsum=maxsum+sum-long(n)*a[n-i];
            if(maxsum>msum)
            {
                msum=maxsum;
            }
        }
        return msum;
    }
};