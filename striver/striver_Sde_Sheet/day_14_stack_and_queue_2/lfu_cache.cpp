#include<bits/stdc++.h>
using namespace std;


struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key,int val) : key(key), val(val), prev(NULL) , next(NULL) {}
};

class LFUCache {
public:
    unordered_map<int,Node*> freqEle;
    unordered_map<int,pair<int,Node*>> keyMap;
    int cacheSize;
    int minFreq;
    
    LFUCache(int capacity) {
        cacheSize = capacity;
        minFreq = 0;    
    }
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end()){
            return -1;
        }

        pair<int,Node*> ele = keyMap[key];

        // but we need a mechanism we should know key and its corresponding node and count times it get called
        // so map of key to its freq + Node 

        // deleteNode(freqEle[ele.first],ele.second); // remove that node from linked list
        Node * newNode = new Node(key, ele.second->val);
        // insertNode(freqEle[ele.first + 1], newNode)
        return ele.second->val;
    }
    
    void put(int key, int value) {
        // if putting in same key , update that

        // if putting new key , insert in minFreq

    }

    void deleteNode(Node *head, Node* node){
        // remove this node 
    }

    void insertNode(Node *head , Node*node){
        // insert this node in head
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */