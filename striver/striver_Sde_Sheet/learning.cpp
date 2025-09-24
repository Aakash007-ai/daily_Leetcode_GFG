#include<bits/stdc++.h>
using namespace std;

// we have to pass has function to unorderd_set of vector<int>
// always take n = size of array if not given (to prevent multiple calculation of size in for loop)
struct Car {
    int id;
    string name;
    Car() : id(0), name("Car"){}
    Car(string name) : name(name) , id(0) {};

};

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x) , next(nullptr) {}
    ListNode(int x , ListNode *next) : val(x), next(next) {}
};

void printVector(vector<int> &nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 4;
    // Car A =new Car();
    // cout<<A.id;
    // cout<<A.name;
    
    cout<<"Printing all major last minutes points :";

    // condition get evaluated every time inside for loop , so it is better to have constant expression. it should not num.size();
    // for loop only cosider the right expression and discard the left condition that is i!= n (as it is comma separated). have have to use && to check both condition
    // for(int i=0; i!=n, i < n;i++){ // use condition in for loop it can be for other variable too, comma separated conditions
    //     cout<<i;
    // }

    ListNode *node = NULL;
    node = new ListNode(3);
    cout<<node->val;


    // //---------------set duplication
    // struct VectorHash {
    //     size_t operator()(const vector<int>& vec) const {
    //         size_t hash = 0;
    //         for (int num : vec) {
    //             hash ^= hasher(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    //         }
    //         return hash;
    //     }
    // };

    // unordered_set<vector<int>, VectorHash> ust;
    // // ust.insert({-1,0,1});
    // ust.insert({-1,1,0});


    // XOR of same number 
    int num = 5 ^ 5;
    cout<<" Xor of same number : "<<num;
}