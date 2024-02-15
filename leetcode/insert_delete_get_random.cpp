#include<bits/stdc++.h>
using namespace std;


class RandomizedSet {
public:
unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            st.insert(val);
            return true;
        }else return false;
    }
    
    bool remove(int val) {
        auto it=st.find(val);
        if(it != st.end()){
            st.erase(val);
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int x=rand() + st.size();
        return *(st.begin());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */