#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        for(int i=left+1;i<=right;i++){
            left &= i;
        }
        return left;
    }
};


int main(){
    int left,right;
    cin>>left>>right;
    Solution obj;
    cout<<obj.rangeBitwiseAnd(left,right);
}