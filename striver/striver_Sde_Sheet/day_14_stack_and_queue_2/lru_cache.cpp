#include<bits/stdc++.h>
using namespace std;


/**
 * brute force
 */
// struct Node {
//     int val;
//     Node* left;
//     Node* right;

//     Node(int val) : val(val) , left(nullptr), right(nullptr) {}
// };

class LRUCache {
    int cacheSize;
    unordered_map<int,Node*> mp;
    Node *head = NULL ,*tail = NULL;
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        updateNode(key);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        // check if key exist or not

        Node* node = NULL;
        if(mp.find(key) == mp.end()){
            //create new at the end
            node = new Node(value);
            mp[key] = node;
            if(!head){ 
                head = node;
                tail = node;
            }
            else {
                tail->right = node;
                tail = tail->right;
            }
        }else{
            node = mp[key];
            node->val = value;
            updateNode(key);
        }

        if(mp.size()>cacheSize){
            head = head->right;
        }
    }

    void updateNode(int key){
        Node* node = mp[key];
        if(tail == node) return ;

        if(head == tail) return ;

        if(node == head){
            Node *newHead = head->right;
            tail->right = head;
            head->left = tail;
            head->right = nullptr;
            head = newHead;
            tail = tail->left;
        }else{
            Node *temp = node;
            node->left->right = node->right;

            tail->left = temp;
            tail = tail->left;
            temp->right = nullptr;
        }


    }
};


/**
 * corrected brute force
 */

 struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToTail(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity): capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        removeNode(node);
        addToTail(node);
        return node->val;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addToTail(node);
        }else{
            if(mp.size() == capacity){
                Node* lru = head->next;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            addToTail(node);
        }
    }
};


/**
 * optimize appraoach
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
//                     this->deleteNode(toDel);
//                     head = head->next;
//                 }
//                 // now we can insert the new element
//                 cache[key] = this->putNode(key,value);
//             }
//         }
//     };
    
// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */