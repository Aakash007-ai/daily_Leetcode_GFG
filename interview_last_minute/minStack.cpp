#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> mnStack;
    stack<int> nStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        nStack.push(val);
        if(mnStack.size() && val <= mnStack.top()){
            mnStack.push(val);
        }
    }
    
    void pop() {
        if(nStack.top()== mnStack.top()) mnStack.pop();
        nStack.pop();
    }
    
    int top() {
        return nStack.top();
    }
    
    int getMin() {
        return nStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */