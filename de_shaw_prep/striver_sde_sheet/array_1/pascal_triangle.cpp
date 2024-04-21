#include<bits/stdc++.h>
using namespace std;


/*
    vector of vector of size numRows
    numRows =1 
    {{1}} ans[0][0] = 1, 

    numRows = 2;
    {   ans[0] = {1} , 
        ans[1]= {1,1}  {ans[2-1-1][], ans[1-1][] 
        {1},{1,1}
    }

    numRows = 3 
    {   
        {1},
        {1,1},
        {1,2,1}
        for i=3, j=2  ans[i-1-1][j-1-1]+ans[i-1-1][j-1]
    }

    numRows = 4
    {
        {1}, i=1
        {1,1}, i=2
        {1,2,1}, i=3
        {1,3,3,1} i=4
        for i=4
        j=1 ans[i-1].push_back(ans[i-1-1])
        j=2 ans[i-1].push_back(ans[i-1-1][j-1]+ans[i-1-1][j-1-1]) i.e 2+1 =3
        j=3 ans[i-1].push_back(ans[i-1-1][j-1]+ans[i-2][j-2])
    }

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};