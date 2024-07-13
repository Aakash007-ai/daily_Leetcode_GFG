#include<bits/stdc++.h>
using namespace std;

bool checkBookings(int totoalRooms,vector<pair<int,pair<int,int>>> bookings , int room, int startDate ,int endDate){
    int n= bookings.size();
    // (room no.,{ startDate, endDate})
    // if(100 - < room) return false;
    int occupiedRooms=0;
    vector<int> arr(100);

    for(int i=0;i<bookings.size();i++){
            if(arr[bookings[i].first] == 1){
                //don't count
            }else{
                // count as oocupied room
                arr[bookings[i].first ] = 1;
                occupiedRooms += bookings[i].first;
            } 
    }

    if(totoalRooms - occupiedRooms < room) return false;

    for(int i=0;i<n;i++){
        //comapre 
       // if(room == bookings[i].first) continue; // already booked room 
        //case 1 if new booking is beyon current , we comapre it with meas end of new is less than beginnenig of i
        // case 2 if new booking is have larger date than current
        if(endDate < bookings[i].second.first || startDate > bookings[i].second.first){
            continue;
        }else{
            return false;
        }        
    }
    return true;
}

// [
//     {roomNo: 1, bookingStartDate: '2022-04-24', bookingEndDate: '2022-04-27'},
//     {roomNo: 2, bookingStartDate: '2022-04-23', bookingEndDate: '2022-04-30'},
//     {roomNo: 1, bookingStartDate: '2022-04-29', bookingEndDate: '2022-04-30'},
// ]
int main(){
    //no. o frooms
    //room no.
    //date 
    int n=100;
    vector<int> a = {1,2,3};
    vector<pair<int,pair<int,int>>> v = {{1,{24,27}} ,{2,{23,30}} , {1,{29,30}}};


    cout<<checkBookings(n,v,4,23,45);
}