
// what do u want 
// how badly u want 
// how much u can sacrifice for that 

// mark cuban  
// there is beautiful thing about success 
// u need to get succceed at once (even failure rate is 99% , but if u got success in 1% u become succeed)
// one big shot and everything


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int res=arr[0];
        int prefix=1,suffix=1;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            prefix*=arr[i];
            suffix*=arr[n-1-i];
            res = max(res,max(prefix,suffix));
            
            if(prefix == 0) prefix=1;
            if(suffix == 0) suffix=1;
        }
        return res;
    }
};
