//aray nums
//constain n+1 int
//where each int must be 1 to n
//there is only one repeated number 
//and it can be any

#include<bits/stdc++.h>
using namespace std;

int main(){
    // arr 1 to n
    vector<int> arr = { 1,3,5,6,2,4,3} ;//n+1
    int n= arr.size();

    unordered_map<int,int> mp;
    for(auto it:arr){
        auto itr = mp.find(it);
        if(itr!=mp.end()){
            //here we get repeated element
        
        }
        else{
            mp[it];
        }
    }


    ///optimised
    // arr is not sorted 
    vector<bool> ans(n);
    for(auto it:arr){
        if(arr[n]){
            //we got the repeating numer
            cout<<"it";
            break;
        }else{
            if(it<arr.size()) ans[it]=true;
            else cout<<it;
        }
    }


    //more optimised
    // for loop over 1 to n and mark that index as 0
    // whatif we conclude bits
    // 10 is written as 
    // bitnumber of  1111111111...n
    //for loop arr
    //and set bit to 0 which is present 


    //
    // create a n number of bit with all bit set to 1
    // if n is 1000
    // n==64
    // for(it : arr) {
        // if( that num is already is unset in assumed) 
            //we got our ans
            //break loop
        //else unset that bit // if the num  is 4 // unset the 4th bit
        //

    // if string size n with 11111
    // o(n)

}