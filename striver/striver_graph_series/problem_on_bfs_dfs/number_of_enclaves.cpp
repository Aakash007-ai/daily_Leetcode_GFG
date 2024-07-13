#include<bits/stdc++.h>
using namespace std;

// code optimized way of surrounded regions
//first choose celss that are on land and fill them with water and do dfs
// then we just need to count number of cells having 1

class Solution {
public:
    void dfs(vector<vector<int>>& A, int i, int j) {
        if (i < 0 || j < 0 || i == A.size() || j == A[i].size() || A[i][j] != 1) return;
        A[i][j] = 0;
        dfs(A, i + 1, j), dfs(A, i - 1, j), dfs(A, i, j + 1), dfs(A, i, j - 1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        for (auto i = 0; i < A.size(); ++i)//find land fill them with water
            for (auto j = 0; j < A[0].size(); ++j) 
                if (i * j == 0 || i == A.size() - 1 || j == A[i].size() - 1) dfs(A, i, j);

        return accumulate(begin(A), end(A), 0, [](int s, vector<int> &r){ 
            return s + accumulate(begin(r), end(r), 0);}
        );
    }
};