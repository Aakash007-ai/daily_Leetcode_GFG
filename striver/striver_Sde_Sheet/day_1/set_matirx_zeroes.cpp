#include<bits/stdc++.h>
using namespace std;

/**
 * if a number is 0 set its entire row and column 0
 * max(m,n) = 200
 * 
 * brute force?
 * first iterate through matrix if we found 0 in between matrix
 * mark their column and row starting 0
 * 
 * iterate over first row, column again ,
 * if we found row is 0 mark entier row 0
 * if we found column starting 0 , mark entire column 0
 * 
 * edge case , if first row or column is 0,
 * at end mark entire row or column 0
 * 
 * so we will just keep a boolean if first row or column has 0 mark that boolean true
 * if it is not first row or column mark first index of row column 0
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool roWZ = false, colZ = false;
        if(matrix[0][0] == 0){
            roWZ = 1;
            colZ = 1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0  && matrix[i][j] == 0 ){
                    roWZ = 1;
                    continue;
                }else if( j==0 && matrix[i][j] == 0){
                    colZ = 1;
                    continue;
                }

                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            if(matrix[i][0] == 0){
                for(int j=1;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1;j<m;j++){
            if(matrix[0][j] == 0){
                for(int i=1;i<n;i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(roWZ){
            for (int j = 0; j < m; j++){
                matrix[0][j]=0;
            }
        }

        if(colZ){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0; 
            }
        }
    }
};


// 289. Game of Life
// 2123. Minimum Operations to Remove Adjacent Ones in Matrix
// 2174. Remove All Ones With Row and Column Flips II