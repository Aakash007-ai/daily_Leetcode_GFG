#include<bits/stdc++.h>
using namespace std;

class Queue {
    private : 
    int start;
    int end ;
    int maxSize;
    int * arr;
    
    public:
    Queue(){
        start = -1;
        end = -1;
        arr = new int[200];
        maxSize = 200;
    };

    void push(int x){
        if(end-start == maxSize){
            cout<<"Queue is full, exiting"<<endl;
            exit(1);
        }

        if(end == -1){ // first element
            end++;
            start++;
        }
        else end++;
        arr[end%maxSize] = x;
    }

    int pop(){
        if(start == -1){
            cout<<"Queue is empty";
            exit(1);
        }

        if(start == end){

        }
        int ele = arr[start%maxSize];
        start++;
        return ele;
    }

    int front(){
        // addd a check for initialized 
        return arr[start];
    }


};