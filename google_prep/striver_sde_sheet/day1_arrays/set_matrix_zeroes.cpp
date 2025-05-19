#include<bits/stdc++.h>
using namespace std;


// brute approach
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//        int n=matrix.size(), m= matrix[0].size();
//        int start = matrix[0][0];
//        bool rowZ = false;
//        bool colZ = false;

//        if(start == 0){
//         rowZ =true;
//         colZ = true;
//        }
//        // avoid 0th index to set it to 0 , just check at the end
//        for(int i=1;i<n;i++){
//         for(int j=1;j<m;j++){
//             if(!matrix[i][j]){
//                 matrix[i][0]=0;
//                 matrix[0][j]=0;
//             }
//         }
//        }

//        // iterate over rows and mark that row whole 0 whose start is 0
//        for(int i=1;i<n;i++){
//         if(matrix[i][0]==0){
//             rowZ=true; //make all colZ = 0 for all for row 0
//             for(int j=1;j<m;j++){
//                 matrix[i][j]=0;
//             }
//         }
//        }

//        //iterate over column and mark that column 0 whose start is 0
//        for(int j=1;j<m;j++){
//         if(matrix[0][j]==0){
//             colZ=true;
//             for(int i=1;i<n;i++){
//                 matrix[i][j]=0;
//             }
//         }
//        }

//        //checking 0th index
//        if(colZ){
//         for(int j=0;j<m;j++){
//             matrix[0][j]=0;
//         }
//        }

//        if(rowZ){
//         for(int i=0;i<n;i++){
//             matrix[i][0]=0;
//         }
//        }
//     }
// };

//optimised apprach with code redundant
class Solution {
public:
        void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(col){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if(row){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }
};

int main(){
    vector<vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    Solution obj;
    int n=arr.size(), m = arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}