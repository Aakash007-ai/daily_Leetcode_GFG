#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left,*right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


//         1
//     2        3
// 4      5  6     7
//preorder first node->left then node then node->right
void printPreorder(TreeNode *node){
    if(!node) return;
    if(node->left) printPreorder(node->left);
    cout<<node->data<<" ";
    if(node->right) printPreorder(node->right); 
}
int main(){
    // int n;
    // cin>>n;//enter number of nodes
    TreeNode *head =  new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);


    cout<<"Preorder of above tree is \n";
    printPreorder(head);


    return 0;

    // for(int i=0;i<n;i++){
    //     int x;
    //     if(i==0){
    //         cout<<"Enter node value";
    //         cin>>x;
    //     }
    // }
    //so fill by default initially

}