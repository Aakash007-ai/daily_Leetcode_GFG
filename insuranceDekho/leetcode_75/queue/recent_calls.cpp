#include<bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        int n;
        while(t-3000 > q.front()){
            q.pop();
        }
        return q.size();    
    }
};

int main(){
    RecentCounter* obj = new RecentCounter();
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

// RecentCounter recentCounter = new RecentCounter();
// recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1  1-3000 = -2999>1
// recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2    100-3000 -2900 > 1
// recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3  3001-3000 =1 >1
// recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3   3002-3000 > q.front() q.pop()return q.size();