#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findRoot(int n, vector<int>& left, vector<int>& right) {
    unordered_set<int> children;
    children.insert(left.begin(), left.end());
    children.insert(right.begin(), right.end());
    
    for (int i = 0; i < n; i++) {
        if (children.find(i) == children.end()) {
            return i;
        }
    }
    
    return -1;
}
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    
        if(n==1){
            if(leftChild[n-1]==-1 && rightChild[n-1]==-1) return true;
            else return false;
        }
        vector<int> vis(n,0);
        queue<int> q;
        int fn=findRoot(n,leftChild,rightChild);
        if(fn==-1) return false;
        q.push(fn);vis[fn]=1;
        while(!q.empty()){
            int v = q.front();q.pop();
            if(leftChild[v] != -1){
                if(!vis[leftChild[v]]){
                    q.push(leftChild[v]);
                    vis[leftChild[v]]=1;
                }else{
                    return false;
                }
            }
            if(rightChild[v] != -1){
                if(!vis[rightChild[v]]){
                    q.push(rightChild[v]);
                    vis[rightChild[v]]=1;
                }else{
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(!vis[i]) return false;
        
        return true;
    }
};