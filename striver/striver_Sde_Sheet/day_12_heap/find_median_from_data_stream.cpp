#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    private:
    priority_queue<int> mxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxHeap.push(num);
        minHeap.push(mxHeap.top());
        mxHeap.pop();

        if(minHeap.size()>mxHeap.size()){
            mxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(mxHeap.size()>minHeap.size()) return (double)minHeap.top();
        else (mxHeap.top()+minHeap.top())/(double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */