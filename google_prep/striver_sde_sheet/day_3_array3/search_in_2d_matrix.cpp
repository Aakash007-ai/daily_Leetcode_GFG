#include<bits/stdc++.h>
using namespace std;

// o(logm*n) means

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         // int is=0, ie=n-1;
//         // while(is <= ie){
//         //     int midIdx = (is+ie)/2;
//         //     int midEle = 
//         //     if(target <= midEle){
//         //         ie=mid;
//         //     }else{
//         //         is=mid+1
//         //     }
//         // }
//         // ie is that row in which ele is there
//         // again for row apply binary search
//     }
// };

// here crux is 2d sorted array is also a soted array

/*
    1  3  5  7     n=3, m=4, so total n*m elements sorted
    10 11 16 20
    23 30 34 50

    int s=0, e=n*m-1;
    int mid = (s+e)/2; i.e. 5  11/2 =5

    so 5 in terms of 2d element  5%4 = 1 it will be in ist row 
*/


class Solution {
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        cout<<"Search matrix function called "<<endl;
        int s=0;
        int e=n*m-1;
        while(s<=e){
            int mid= (s+e)/2;
            int i=mid/m;
            int j=mid%m;
            cout<<"starting idx "<<s<<" ending idx "<<e<<endl;
            cout<<i<<" "<<j<<" "<<mid <<endl;
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    Solution obj;
    cout<<obj.searchMatrix(matrix, 3);
}