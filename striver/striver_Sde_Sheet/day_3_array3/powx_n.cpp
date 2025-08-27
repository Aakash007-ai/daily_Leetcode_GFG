#include<bits/stdc++.h>
using namespace std;

// always start with loop instead of recursive as recursive takes memory overflow issue  for large cases

//  also check for constraints , if calculations 
/**
 * if  -2^31 <= n <= 2^31-1 , it means we can't even multiply n with -1 as it cause overflow issue
 * here check carefully int is in the range of this with signed digits,,
 * eiteher takes a new vairable with different type and assign it to them
 * 
 * also check we are decreasing by n times for below solution it will give time limit exceed . as by default it is exceeding memory  
 */

class Solution {
public:
    // double myPow(double x, int n) {
    //     double ans = 1;
    //     if(x == 1) return x;
    //     if(n<0){
    //         n *= -1.00;
    //         x = 1/x;
    //     }
    //     if(n==0) return 1;
    //     while(n){
    //         ans*=x;
    //         n--;
    //     }
    //     return ans;
    // }


        double myPow(double x, long long n) {
        double ans = 1;
        if(x == 1) return x;
        if(n<0){
            n *= -1.00;
            x = 1/x;
        }
        if(n==0) return 1;
        while(n){
            if(n%2 == 1){
            ans*=x;
            n--;
            }else{
                x*=x;
                n= n/2;
            }
        }
        return ans;
    }
};