#include<bits/stdc++.h>
using namespace std;
//by greedy where we take sum of the 2 child
/*
    if we go left then we mark it as 
*/
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class comp{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};


class Solutions{
    public:
    void traverse(Node* root,vector<string> & ans, string temp){
        if(root->left ==NULL && root->right==NULL){
            ans.push_back(temp);
            return ;
        }

        traverse(root->left,ans,temp+'0');
        traverse(root->right,ans,temp+'1');
    }
    vector<string> huffmanCoding(string s,vector<int> f,int n){
        priority_queue<Node *, vector<Node *>, comp> pq;

        for(int i=0;i<n;i++){
            Node * temp = new Node(f[i]);
            pq.push(temp);
        }

        while(pq.size()>1){
            Node* left = pq.top();pq.pop();
            Node* right = pq.top();pq.pop();

            Node* newNode= new Node(left->data+right->data);

            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node* root=pq.top();
        vector<string> ans;
        traverse(root,ans,"");
        return ans;
    }
};