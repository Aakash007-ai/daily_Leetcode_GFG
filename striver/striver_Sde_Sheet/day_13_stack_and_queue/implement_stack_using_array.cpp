#include<bits/stdc++.h>
using namespace std;


class Stack {
    private:
    int maxSize;
    int top;
    int * arr;
    public:
    Stack(){
        maxSize  = 1000;
        top = -1;
        arr = new int[maxSize];
    }

    void push(int num){
        top++;
    }

    void pop(){
        int x = arr[top];
        top--;
    }
};

int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
}