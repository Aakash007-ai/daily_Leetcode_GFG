#include<bits/stdc++.h>
using namespace std;

// always write a smaple case and dry run over it, 

class Solution {
public:
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int s=0, e = r*c-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int x = mid/c;
            int y = mid%c;

            if(target == matrix[x][y]) return true;
            if(matrix[x][y]>target) e= mid-1;
            else s=mid+1;
        }
        return false;
    }
};