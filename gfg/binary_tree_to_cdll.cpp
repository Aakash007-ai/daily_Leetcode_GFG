#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
  public:
    Node* head=NULL;
    void inorder(Node *root,Node * tail){
        if(root->left) inorder(root->left,tail);
        Node * temp = new Node(root->data);
        tail=temp->right;
        if(head==NULL) head=temp;
        if(root->right) inorder(root->right,tail);
    }
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root){
        Node * tail=NULL;
        //at last we got a inorder version where head always point at first and right always point at next
        //now we want to point left and we know tail is last element
        if(root==NULL) return NULL;
        inorder(root,tail);
        Node* temp=head;
        temp->left = tail;
        temp=temp->right;
        

        
    }   
};
