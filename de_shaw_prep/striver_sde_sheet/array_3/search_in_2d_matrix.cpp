#include<bits/stdc++.h>
using namespace std;


//true if target is in matrix
//so search in that row where next row starting element is high
//first binary search on row then pick up the column

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

//for t=3 e is ans e, again for 13 ans is e

//mxn matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int s=0,e=n-1;
        while(s<=e){//will break when s==e and thats is row where we have to search
            int mid=s +(e-s)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0] < target) s=mid+1;
            else if (matrix[mid][0]>target) e=mid-1;
        }
        if(e<0) return false;

        int m=matrix[0].size();//s is ans as e goes beyoinf for 4
        int x=0;//if s==m ans is e
        int y=m-1;
        while(s<=e){
            int mid=x+(y-x)/2;
            if(matrix[e][mid]==target) return true;
            else if(matrix[e][mid] < target) x=mid+1;
            else if(matrix[e][mid] > target) y=mid-1;
        }
        if(s==m) return false;
    }
};



//optimized approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(), m=mat[0].size();
        int l=0, r=n*m-1;
        
        while(l <= r){
            int mid = l+(r-l)/2;
            int x = mat[mid/m][mid%m];
            
            if(x > target){
                r = mid-1;
            }else if(x < target){
                l = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};