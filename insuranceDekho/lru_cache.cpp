#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(int val){
        cout<<"Creating new node"<<endl;
        value=val;
        left=nullptr;
        right=nullptr;
    }
};

class LRUCache {
    void rearrange(Node * src,Node *front,Node *end){
        cout<<"rearrange start"<<endl;
        if(src==front){
            cout<<"src==front"<<endl;
            //then just put it at last
            Node *temp=front;
            front=front->right;//we updated front
            front->left=NULL;
            end->right=temp;
            end=end->right;//we updated end
            return;
        }else if(src==end){
            cout<<"src==end"<<endl;
            //do nothing just return
            return;
        }

        cout<<"element is in between front and end"<<endl;

        Node * temp=src;
        Node *prevNode = temp->left;
        Node *nextNode = temp->right;
        nextNode->left=prevNode;
        prevNode->right=nextNode;
        //remove that node
        end->right=temp;
        end=end->right;
        //put that node at end;
        return;
    }
public:
    int n; //space in list
    int capacity;
    unordered_map<int,Node *> mp;
    Node *front=nullptr,*end=nullptr;
    LRUCache(int capacity) {
        cout<<"starting lru cache constructor"<<endl;
        this->n=capacity;//initialyy all space are empty
        this->capacity=capacity;
    }
    
    int get(int key) {
        //we check it in a unordered map
        cout<<"gt key "<<key<<endl;
        if(mp.find(key)!= mp.end()){
            cout<<"key is there and its value is "<<endl;
            //then get that 
            int val=mp[key]->value;
            //rearrange that node to last
            rearrange(mp[key],front,end);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //if already there then rearrange
        cout<<"put request received key "<<key<<" value "<<value;
        if(mp.find(key) != mp.end()){
            //already there
            rearrange(mp[key],front,end);
            return;
        }

        Node* neo = new Node(value);
        mp[key]=neo;
        if(n==capacity){
            //first element
            front=neo;
            end=neo;
            mp[key]=neo;
            n--;
            cout<<"new node created"<<endl;
            return;
        }else if(n==0){
            Node *hold=front;
            delete hold;

            front=front->right;
            front->left=nullptr;

            end->right=neo; //add to last
            neo->left=end;
            end=neo;
            return ;
        }
        //we have space left just put it to end
        cout<<"adding new node to end"<<endl;
        end->right=neo;
        neo->left=end;
        end=neo;
    
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    cout<<"start main"<<endl;
    int k;cin>>k;
    LRUCache* obj= new LRUCache(k);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1);
    obj->put(3,3);
    cout<<obj->get(2);
    // obj->put(4,4);
    // cout<<obj->get(1);
    // cout<<obj->get(2);
    // cout<<obj->get(4);
    cout<<"end main";
}