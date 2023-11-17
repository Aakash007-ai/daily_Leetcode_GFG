#include<bits/stdc++.h>
using namespace std;
//3 5 0 0 4
//    i   j
//3 5 4 0 0
//    i   j



//0 0 0 4
//i     j
//4 0 0 0
//  i      j



//4 0 0 0

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
        int c = 0;
        int i=0,j=0;//i will stop at first 0 and j will stop at first non zero after i stops and then swaps
        while(i<n && j<n){
            if(arr[i]==0){
                if(!c) {j=i+1;c++;}
                while(j<n){
                    if(arr[j]!=0){
                        swap(arr[i],arr[j]);
                        i++;
                        break;
                    }
                    j++;
                }
            }else{
                i++;
            }
        }
	}
};