#include<bits/stdc++.h>
using namespace std;

// In the previous implementation of the “disjoint set”, notice that to find the root node, we need to traverse the parent nodes sequentially until we reach the root node. 
// If we search the root node of the same element again, we repeat the same operations. 
// Is there any way to optimize this process?

// After finding the root node, we can update the parent node of all traversed elements to their root node. 
// When we search for the root node of the same element again, we only need to traverse two elements to find its root node, which is highly efficient.

// So, how could we efficiently update the parent nodes of all traversed elements to the root node? The answer is to use “recursion”. 
// This optimization is called “path compression”, which optimizes the find function.


//in quick union we have possibilty of creating a sinle line of node,
// we move one step closer to that optimization

class UnionFind{
    private:
    vector<int> root;

    public:
    UnionFind(int sz): root(sz){
        for(int i=0;i<root.size();i++){
            root[i]=i;
        }
    }

    int find(int x){
        if(x==root[x]){
            return x;
        }
        root[x]=find(root[x]);
    }

    void unionSet(int x,int y){
        int rootX=find(x);
        int rootY=find(y);

        if(rootX!=rootY){
            root[rootY]=rootX;
        }
    }

    bool connected(int x,int y){
        return find(x)==find(y);
    }
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

    return 0;
}

// Note: N is the number of vertices in the graph.

// As before, we need 
// O(N) time to create and fill the root array.
// For the find, union, and connected operations (the latter two operations both depend on the find operation), we need 
// O(1) time for the best case (when the parent node for some vertex is the root node itself). In the worst case, it would be 
// O(N) time when the tree is skewed. However, on average, the time complexity will be 
// O(logN). Supporting details for the average time complexity can be found in Top-Down Analysis of Path Compression where R. Seidel and M. Sharir discuss the upper bound running time when path compression is used with arbitrary linking.
// Space Complexity
// We need O(N) space to store the array of size N.


// 	              Union-find Constructor	Find	Union	Connected
// Time Complexity	    O(N)                O(logN)	O(logN)	O(logN)