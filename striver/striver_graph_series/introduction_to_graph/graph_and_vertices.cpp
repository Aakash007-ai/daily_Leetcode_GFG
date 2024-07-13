#include<bits/stdc++.h>
using namespace std;

// how many undirected graph can be formed from n vertices (nodes)
class Solution {
  public:
    long long count(int n) {
        /*
            Suppose there are n no of nodes. n=4 we suppose.
            Then no 1 node can connect with 3 different node with 3 unique edges -
            a. 1-2
            b. 1-3
            c. 1-4
            Again no 2 can connect with 2 uniq ue edges and one common edge(1-2)
            d. 2-3
            e. 2-4
            Again no 3 can connect with 1 unique edge and 2 common edges(1-3, 2-3)
            f. 3-4
            And for no 4 node, we have all common edges(4-1, 4-2, 4-3)
            So for all combination, there can be total 3+2+1 = 6 unique edges
            So total unique edges for n nodes can be sum of 1 to n-1 = n(n-1)/2
            And posibilty for drawing each edge is 2
            So combinations = 2^((n*(n-1))/2)
        */

        return 1LL<<((n*(n-1))/2);

    }

};

 long long count(int n) {
        //total edges possible 
        /*
           since every node can be connected to n-1 other nodes so for n nodes total edges possible are n*(n-1) OR n*n(if 
           self node is allowed) but since here undirected graph is being considered so edge from a to b would be same as edge 
           from b to a and hence divided by 2;
        */

        int total_edges=n*(n-1)/2;
        //now for every edge we have two options whether to consider it or not 

        return 1ll*pow(2,total_edges);
    }