#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Solution
{
    public:
    Node *head=NULL;
    void insert_first(struct Node * node,int data){
        struct Node *n=new Node;
        n->data=data;
        n->next=head;
        head=n;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        while(node1 && node2){
            if(node1->data <= node2->data){
                insert_first(node1,node1->data);
                node1=node1->next;
            }
            else{
                insert_first(node2,node2->data);
                node2=node2->next;
            }
        }
        if(node1){
            while(node1){
                insert_first(node1,node1->data);
                node1=node1->next;
            }
        }
        else{
            while(node2){
                insert_first(node2,node2->data);
                node2=node2->next;
            }
        }
       return head; 
    }  
};


//so merging 2 linked list of variable size in decreasing order given ll is in sorted order
// class Solution{
//     public:
//     //so either go in last and do backtracking
//     struct Node * mergeResult(Node *node1,Node *node2){
//         if(!node1 && !node2) return NULL;
//         stack<int> st;
//         while(node1 || node2){
//             if(node1 && node2){
//                 if(node1->data <= node2->data){
//                     st.push(node1->data);
//                     node1 = node1->next;
//                 }else{
//                     st.push(node2->data);
//                     node2=node2->next;
//                 }
//             }else if(node1){
//                 st.push(node1->data);
//                 node1=node1->next;
//             }
//             else if(node2){
//                 st.push(node2->data);
//                 node2=node2->next;
//             }
//         }

//         Node *merged = new Node(); 
//         Node *temp = NULL; 
//         temp=merged->next;

//         while(!st.empty()){
//             temp = new Node();
//             temp->data = st.top();
//             temp=temp->next;
//             st.pop();
//         }
//         return merged->next;
//     }  
// };