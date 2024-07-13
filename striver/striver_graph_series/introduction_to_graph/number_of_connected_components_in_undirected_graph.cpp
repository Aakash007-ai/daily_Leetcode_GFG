#include<bits/stdc++.h>
using namespace std;

// iota(arr.begin(), arr.end(),5) put 5 in first index and then incremnet, it do unntil we reach at end
//check commented code

//find number of sub graphs
// only way is to find travers
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> arr[n];
        for(auto it:edges){
            arr[it.front()].push_back(it.back());
            arr[it.back()].push_back(it.front());
        }
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                // dfs(i,arr,visited);
            }
        }
        return count;
    }
};




// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<int> p(n);
//         iota(p.begin(), p.end(), 0);
//         for (int i = 0; i < n; ++i) p[i] = i;
//         function<int(int)> find = [&](int x) -> int {
//             if (p[x] != x) p[x] = find(p[x]);
//             return p[x];
//         };
//         for (auto& e : edges) {
//             int a = e[0], b = e[1];
//             p[find(a)] = find(b);
//         }
//         int ans = 0;
//         for (int i = 0; i < n; ++i) ans += i == find(i);
//         return ans;
//     }
// };