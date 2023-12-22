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
    bool ans = true;
    void solve(Node *r1,Node *r2){
        if(ans){
            if(r1 && r2){
                if(r1->data == r2->data){
                    solve(r1->left,r2->left);
                    if(ans) solve(r1->right,r2->right);
                }
            }else{//may be one of r1 and r2 is true
                if(r1 || r2){
                    ans=false;
                }//our mistake both are false moveon
            }
        }
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        solve(r1,r2);
        return ans;

    }
};