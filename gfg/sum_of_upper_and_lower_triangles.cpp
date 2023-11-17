#include<bits/stdc++.h>
using namespace std;


class Solution{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n){
        int upperSum=0,lowerSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>=i){
                    upperSum += matrix[i][j];
                }
                if(j<=i){
                    lowerSum += matrix[i][j];
                }
            }
        }
        return {upperSum,lowerSum};
    }
};