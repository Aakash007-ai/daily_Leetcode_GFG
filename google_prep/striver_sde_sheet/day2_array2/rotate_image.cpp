#include<bits/stdc++.h>
using namespace std;

/*
    1  2  3  4              13 9  5 1
    5  6  7  8    ---->     14 10 6 2 
    9  10 11 12   ----->    15 11 7 3
    13 14 15 16             16 12 8 4
*/

/*
    swap i,j with i,j+n
    swap i,j with i+n,j
    swap i+n,j with i+n,j+n

    for 0,0
    swap 0.0   0.n-0
    swap 0.0   0+n.0
    swap 0+n.0  0+n.0+n

    for 0.1
    swap i.j  j.n-i    8   2
    swap i.j  n-1.i
    swap n-j, n-i,n-j

    for 0,2
    swap 0.2 2.n
    
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n/2;j++){
                swap(matrix[i][j], matrix[j][n-i]);

                swap(matrix[j][i],matrix[n-i][j]);
            }
        }   
    }
};