#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
};

class Solution{
private:

public:
    // 1  fails for this input
    // 1 2 2 2 2 1 2 N N N N 1 1 N N N N N N
    // 1
    // 1 ans is 2 2
    //can't work because our work for distinct elements
    vector <int> KDistanceNodes(Node* root, int target , int k){
        // return the sorted vector of all nodes at k dist
        //first create a list of graph
        if(root == NULL) return {};
        if(root->data ==target) return {root->data};
        //have to do a bfs to find root node and generate a complete list
        unordered_map<Node *,vector<Node *>> adjList;
        unordered_map<Node *,int> vis;
        //now create list
        Node* tar=NULL;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node * node=q.front();q.pop();
            vis[node]=0;//store in map to mark as visited later
            if(node->data==target){
                tar=node; //there we get our target node
            }
            if(node->left!=NULL){
                adjList[node].push_back(node->left); //store its left children it exist
                adjList[node->left].push_back(node);

                q.push(node->left);
            }
            if(node->right!=NULL){
                adjList[node].push_back(node->right); //store its left children it exist
                adjList[node->right].push_back(node); //children also store its parent
                
                q.push(node->right);
            }
        }

        //now start queue to make bfs
        queue<Node*> qu;
        qu.push(tar);
        while(k-- && !qu.empty()){
            int n=qu.size();//level order traversing and putting all children in queue of currrent level
            for(int i=0;i<n;i++){
                Node* node = qu.front();qu.pop();
                vis[node]++;
                for(auto it:adjList[node]){
                    if(!vis[it]){
                        qu.push(it);
                        vis[it]++;
                    }
                }
            }
        }
        //k becomes 0 or q become empty no element
        if(qu.empty()) return {};
        vector<int> ans;
        while(!qu.empty()){
            Node* n= qu.front();qu.pop();
            ans.push_back(n->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
