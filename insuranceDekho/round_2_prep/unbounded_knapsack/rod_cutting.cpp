#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/* find maximum value obtainable of rods after cutting

    we have to find total length of rod is n
    consider 1 based indexing
    to cut rod by ith price is price[i]
    
    so at any point length of rod is n
    and we are at index i
    we have choice to choose that rod if n>=i
    else skip to less index
*/
class Solution{
  public:
    int solve(int i,int len,int price[]){
        if(len==0) return 0;
        if(i==0) return INT_MIN;

        if(len >= i){
            //we have choice whether to pick it or skip it
            return max(price[i-1] + solve(i,len-i,price), solve(i-1,len,price));
        }
        //else skip it
        return solve(i-1,len,price);
    }
    int cutRod(int price[], int n) {
        return solve(n,n,price);    
    }
};

int main(){
    int n;cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    Solution obj;
    cout<<obj.cutRod(price,n);
}