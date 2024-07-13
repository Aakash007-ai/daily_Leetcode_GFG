#include<bits/stdc++.h>
using namespace std;

//we have to print adjacency list 
/* 
    a list which describe from this node we can move to which node
    a parent and its all children
    // vector<vector<int>> v(no.of nodes) or 
    vector<int> a[no. of nodes] , array which store data of type vector of type int
    like array of vector int a[] , an array which store data of type int
    for directied push as v[src].push_back(dest)
    for undirected v[src].push_back(dest), v[dest].push_back(src)
*/

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> list(V);
        for(auto it:edges){
            list[it.first].push_back(it.second);
            list[it.second].push_back(it.first);
        }
        return list;
    }
};