#include<bits/stdc++.h>
using namespace std;


class MyStack {
public:
    queue<int> primary;
    queue<int> secondary;

    MyStack() {
        
    }
    
    void push(int x) {
        secondary.push(x);
        while(!primary.empty()){
            int ele = primary.front();primary.pop();
            secondary.push(ele);
        }

        queue<int> temp;
        temp = primary;
        primary = secondary;
        secondary = temp;
    }
    
    int pop() {
        int ele = primary.front();primary.pop();
        return ele;
    }
    
    int top() {
        int ele  = primary.front();
        return ele;
    }
    
    bool empty() {
        return primary.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */