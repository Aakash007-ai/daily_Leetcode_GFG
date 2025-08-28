#include<bits/stdc++.h>
using namespace std;

// The functions get and put must each run in O(1) average time complexity.
// so get and put work in O(1) time complexity for unordered_map

// but before put we need to check if cache is empty , then just put
// if that key already present or not
// if present then update the value and update its time with latest
// if not present then check if cache is full or not
// if cache is full then remove the least recently used element
// and then insert the new element

//so in all these operation we need o(1) time complexity
// so we have to use unorderd_map and something that maintian order in o(1), delete and insert in o(1)
// we achieve this by using doubly linked list
// so we will use doubly linked list to maintain the order of elements

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// class LRUCache {
//     private:
//        int capacity;
//        struct Node {
//         int key;
//         int value;
//         Node* next;
//         Node* prev;
//         Node(int key, int val): key(key), value(val), next(NULL), prev(NULL) {}
//        };
//        Node *head=NULL;
//        Node *tail=NULL;
//        unordered_map<int, Node*> cache; // key -> node

//        void deleteNode(Node* node){
//         // we are calling delete node means it is there , 
//         // but don't know whether it is head or tail or in between

//         //if it is not head
//         // if(node->prev!=NULL){
//         //     node->prev->next = node->next;
//         // }else if(node==head){
//         //     // if it is head
//         //     head = node->next;
//         // }

//         Node* prevv = node -> prev;
//         Node* nextt = node -> next;

//         prevv -> next = nextt;
//         nextt -> prev = prevv;


//         delete node;
//        }

//        Node* putNode(int key , int value){
//         Node * node =new Node(key ,value);
//         // if head is null then we have to insert the first node
//         if(head==NULL){
//             head = node;
//             tail = node;
//             return node;
//         }

//         // if head is not null then we have to insert the node at the end
//         tail->next = node;
//         node->prev = tail;
//         tail = node;

//         return node;
//        }
//     public:

//         LRUCache(int capacity) {
//             this->capacity = capacity;
//         }
        
//         int get(int key) {
//             // so we have to check if key is present in cache or not,
//             // if key is present then we have to return the value and update the order of the node
//             // if key is not present then we have to return -1
//             if(cache.find(key)!=cache.end()){
//                 // means key is present , return the value and update the order
//                 Node* node = cache[key];
//                 int value = node->value;
//                 // delete the node from the list
//                 this->deleteNode(node);
//                 // put the node at the end of the list
//                 Node* newNode = this->putNode(key,value);
//                 cache[key] = newNode;
//                 return value;
//             }else {
//                 // means key is not present , return -1
//                 return -1;
//             }
//         }
        

//         void put(int key, int value) {
//             // so we have to check if key is present in cache or not,
//             // if key is present then we have to update the value and update the order of the node
//             // if key is not present then we have to check if cache is full or not
//             // if cache is full then we have to remove the least recently used element
//             // and then insert the new element

//             if(cache.find(key)!=cache.end()){
//                 // means key is present , delete and update

//                 Node* toDel = cache[key];
//                 cache.erase(key);
//                 this->deleteNode(toDel);
//                 cache[key] = this->putNode(key,value);

//             }else {
//                 // means key is not present , check if cache is full or not
//                 if(cache.size()>=capacity){
//                     // means cache is full , remove the least recently used element
//                     // so we have to remove the head node
//                     Node* toDel = head;
//                     cache.erase(head->key);
//                     this->deleteNode(head);
//                     head = head->next;
//                 }
//                 // now we can insert the new element
//                 cache[key] = this->putNode(key,value);
//             }
//         }
//     };


// maintain single repsonsibility principle


class LRUCache {
    public:
        class Node{
            public: 
                int key;
                int val;
                Node* prev;
                Node* next;
    
                Node(int key, int val){
                    this->key = key;
                    this->val = val;
                }
        };
    
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
    
        int cap;
        unordered_map<int, Node*> m;
    
        LRUCache(int capacity) {
            cap = capacity;
            head -> next = tail;
            tail -> prev = head;
        }
    
        void addNode(Node* newnode){
            Node* temp = head -> next;
    
            newnode -> next = temp;
            newnode -> prev = head;
    
            head -> next = newnode;
            temp -> prev = newnode;
        }
    
        void deleteNode(Node* delnode){
            Node* prevv = delnode -> prev;
            Node* nextt = delnode -> next;
    
            prevv -> next = nextt;
            nextt -> prev = prevv;
        }
        
        int get(int key) {
            if(m.find(key) != m.end()){
                Node* resNode = m[key];
                int ans = resNode -> val;
    
                m.erase(key);
                deleteNode(resNode);
                addNode(resNode);
    
                m[key] = head -> next;
                return ans;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(m.find(key) != m.end()){
                Node* curr = m[key];
                m.erase(key);
                deleteNode(curr);
            }
    
            if(m.size() == cap){
                m.erase(tail -> prev -> key);
                deleteNode(tail -> prev);
            }
    
            addNode(new Node(key, value));
            m[key] = head -> next;
        }
    };
    
    