// #include<bits/stdc++.h>
// using namespace std;
// //by default we think of  o(n+m) space complexity,
// //and we think of hard recursive way of optimising in o(1) space
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<pair<int,int>> rc;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]==0){
//                     rc.push_back({i,j});
//                 }
//             }
//         }
//          //e.g. if i=1,j=1 for all i=0 to n , j=1 fill it with 0 |ly for i=1, fill j=0 to n
//         for(auto it:rc){
//             for(int i=0;i<matrix.size();i++){
//                 matrix[i][it.second]=0;
//             }
//             for(int j=0;j<matrix[0].size();j++){
//                 matrix[it.first][j]=0;
//             }
//         }
//     }
// };

// //how we have to think
// //so , we check that if we are making 0 in all row and column while we later have discrepencies 
// //and if we don any change we lost our info
// //so we have to do both make changes instant keeping i mind we are not having discrepencies later
// //one best part is that in later part we may have discrepencies not in earlier part
// //so just thnik what we can change in earlier part and we have information to get answer later
// //we can mark first row and column 0 and later we can set whole row or column to 0 
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int col0=1;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]==0){
//                     //mark the matrix[i][0]=0 the first column of that row, matrix[0][j] mark the first row as 0
//                     matrix[0][j]=0;//whole jth col will be 0 as indicated by first row   
//                     if(j=0){//if we at col = 0, and we get ith row is 0 then whole col0 mark as 0
//                         col0=0;
//                     }else{
//                         matrix[i][0]=0;
//                     }
//                 }
//             }
//         }
//         //now fill up jth column if first row has 0 , keep in mind if mat[0][0] =0 it meas whole row is 0, if col0=0 then fill whole column
//         //for col==0 check each row and fill that row f
//         for(int i=0;i<matrix.size();i++){
//             if(matrix[i][0]==0){
//                 for(int j=1;j<matrix[0].size();j++){
//                     matrix[i][j]=0;
//                 };
//             }
//         }


//         //now for row0=x
//         for(int j=0;j<matrix[0].size();j++){//so traversing over first row and filling coluns
//             if(!matrix[0][j]){
//                 if(j==0){
//                     if(col0==0){
//                         //fill it else continue
//                         for(int i=0;i<)
//                     }
//                     else{
//                         continue;
//                     }
//                     //fill it if col0 is 0 else continue
//                 }
//                 //mark that column 0
//             }
//         }
//     }
// };