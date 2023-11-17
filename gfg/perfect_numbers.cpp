#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    //     int isPerfectNumber(long long N){
    //     long long sum=0;
    //     for(int i=1;i<sqrt(N);i++){
    //         if(N%i==1) sum+=i;
    //     }
    //     return sum==N?1:0;
    // }
    int isPerfectNumber(long long N){
        long long sum=0;
        for(int i=1;i<N;i++){
            if(N%i==0) sum+=i;
        }
        return sum==N?1:0;
    }
};