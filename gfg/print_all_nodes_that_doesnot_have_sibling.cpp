// #include<bits/stdc++.h>
// using namespace std;

// // Tree node structure  used in the program
//  struct Node
//  {
//      int data;
//      Node* left, *right;
// };

// vector<int> noSibling(Node* node){
//     stack<Node*> st;
//     vector<int> v;
//     st.push(node);
//     while(!st.empty()){
//         auto 
//         if(node->right && node->left){
//             st.push(node->left);
//             st.push(node->right);
//         }else if(node->right && !node->left){
//             v.push_back(node->right->data);
//             st.push(node->right);
//         }else if(node->left && !node->right){
//             v.push_back(node->left->data);
//             st.push(node->left);
//         }else{
//             //do nothing
//         }
//     }
// }