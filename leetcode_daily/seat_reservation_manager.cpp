#include<bits/stdc++.h>
using namespace std;

class SeatManager {
public:
    map<unsigned int,int> mp;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            mp[i]=0;//currently seats are unreserverd
        }
    }
    
    int reserve() {
        for(auto it:mp){
            if(!it.second){
                mp[it.first]++;
                return it.first;
            }
        }
    }
    

    void unreserve(int seatNumber) {
        mp[seatNumber]=0;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */