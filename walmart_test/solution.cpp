//ARRAY NUMS 
//have 2n elements
// [x1,x2,......xn..y1,y2..yn]
// x1,y1,x2y2 return in this form
// total n =500
// max sizew of arr[i] <1000 

#include<bits/stdc++.h>
using namespace std;

vector<int> ans(){

}

//2^32  // 256
//max bits is 10

int main(){
    // int n;
    // cin>>n;//half size
    // vector<int> arr(2*n);
    // for(int i=0;i<2*n;i++){
    //     cin>>arr[i];
    // }

    vector<int> arr ={1,2,3,4};
    int n= 2;


    //bits 10 bits e.g. size of arary
    //



    // 5 3 6 24 6 8
    // n=3
    // 0-2

    // 5 24 3 6 6 8 expected output

    // for i=0;
    // arr[i] then swap arr[i+1] with arr[i+n]
    //5 24 6 3 6 8

    // for i=1
    // 












    

    //constraints no new array
    //time complexit will be o(n)

    // while traversing over array we have to shift next element for later use
    //what if we can modify start from start and end approach

    // first conserve next elements (either by swaping or changing its location)
    // 

    // for i = 0; temp = arr[i+1],
    // swap arr[i+1] with arr[i+n];
    //


    
    
    vector<int> ans;
    for(int i=0;i<n;i++){
        // cout<<arr[i]<<" "<<arr[i+n]<<" ";
        ans.push_back(arr[i]);//0
        ans.push_back(arr[i+n]);//
    }

    for(int i=0;i<2*n;i++){
        cout<<ans[i]<<" ";
    }
}