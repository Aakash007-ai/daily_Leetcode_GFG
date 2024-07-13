#include<bits/stdc++.h>
using namespace std;
//binary search tree, a tree in whhich left subtree has less key value than parent
// and right subtree node keys has greater value than parent

//since a node contain address to left and right node and a value
struct Node{
    int val;
    Node *left,*right;
    Node(int data){
        this->val=data;
        left=NULL;
        right=NULL;
    }
};

// insert function , since it should return that node, and it takes root of tree and data to put
Node* insertBST(Node *root, int data){
    //base condition if root is null
    if(root==NULL){ //always go for brute force approach and trusted and known whether it takes more space and time
        return new Node(data);
    }

    if(root->val > data){
        root->left = insertBST(root->left,data);
    }else{
        root->right = insertBST(root->right,data);
    }

    return root;

    //so we comapre with root
    // Node *temp=root;
    // while(temp){
    //     if(temp->val > data){
    //         //data should be put in left sub tree
    //         temp=temp->left;
    //     }else{
    //         temp=temp->right;
    //     }
    // }
    // temp = new Node(data);
    // return root;
}

int main(){
    // first write hard coded then if time is there change it
    //int n;cin>>n;//taking number of nodes
    Node * root= NULL;
    root=insertBST(root,5);
    insertBST(root,8);
    insertBST(root,7);
    insertBST(root,2);
    insertBST(root,4);
    inorder
}
