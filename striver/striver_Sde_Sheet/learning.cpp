#include<bits/stdc++.h>
using namespace std;

    void printVector(vector<int> &nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }

int main(){
    int n = 4;
    cout<<"Printing all major last minutes points :";

    // condition get evaluated every time inside for loop , so it is better to have constant expression. it should not num.size();
    // for loop only cosider the right expression and discard the left condition that is i!= n (as it is comma separated). have have to use && to check both condition
    for(int i=0; i!=n, i < n;i++){ // use condition in for loop it can be for other variable too, comma separated conditions
        cout<<i;
    }
}