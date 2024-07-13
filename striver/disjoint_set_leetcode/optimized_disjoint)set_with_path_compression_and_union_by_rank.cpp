#include<bits/stdc++.h>
using namespace std;

class UnionFind{
    private:
    vector<int> root;
    vector<int> rank;
    public:
    UnionFind(int sz):root(sz),rank(sz){
        for(int i=0;i<root.size();i++){
            root[i]=i;
            rank[i]=1;
        }
    }

    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }

    void unionSet(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                root[rootY]=rootX;
            }
            else if(rank[rootX]<rank[rootY]){
                root[rootX]=rootY;
            }else{
                root[rootY]=rootX;
                rank[rootX]++;
            }
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
// Time Complexity
//             Union-find Constructor	Find	Union	Connected
// Time Complexity	    O(N)	      O(α(N))	O(α(N))	 O(α(N))

// Note: 
// N is the number of vertices in the graph. 
// α refers to the Inverse Ackermann function. In practice, we assume it's a constant. In other words, 

// O(α(N)) is regarded as 
// O(1) on average.
// For the union-find constructor, we need to create two arrays of size N each.
// When using the combination of union by rank and the path compression optimization, 
// the find operation will take O(α(N)) time on average. Since union and connected both make calls to find and all other operations require constant time, 
// union and connected functions will also take O(α(N)) time on average.
// Space Complexity
// We need O(N) space to store the array of size N.