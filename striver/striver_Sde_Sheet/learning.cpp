#include<bits/stdc++.h>
using namespace std;

// https://cs61.seas.harvard.edu/site/2021/Section1/#:~:text=Objects%20of%20KEY%20type%20must%20be%20comparable%2C,are%20returned%20in%20increasing%20order%20by%20key.
// https://cs61.seas.harvard.edu/site/2025/Datarep/

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


    // // XOR of same number 0
    // int num = 5 ^ 5;
    // cout<<" Xor of same number : "<<num;


    // // by default it is max heap
    // priority_queue<int> pq;
    // pq.push(1);
    // pq.push(2);
    // pq.push(3);
    // cout<<"top element of pq "<<pq.top();

    priority_queue<int,vector<int> , greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout<<"to element of min heap "<< pq.top() <<endl;


    auto comp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);

    // stack
    stack<int> st ;
    st.push(10);
    st.pop();
    cout<<"size of stack st filled "<<st.size()<<endl;
    cout<<"is Stack empty"<<st.empty()<<endl;
    
    queue<int> qu;
    qu.push(3);
    qu.push(4);
    qu.pop();
    cout<<"last element of qu"<<qu.front()<<endl;
    qu.pop();
    cout<<"last empty eleme is"<<qu.front()<<endl;

    // valid parenthesis
    // string abc = "{[()]}";
    // stack<char> stc;
    // for(int i=0;i<abc.size();i++){
    //     switch (abc[i])
    //     {
    //     case '}':
    //         if(st.top() == '{') st.pop();
    //         else return false;
    //         break;
    //     case ']':
    //         if(st.top() == '[') st.pop();
    //         else return false;
    //         break;
    //     case ')':
    //         if(st.top() == '(') st.pop();
    //         else return false;
    //         break;
    //     default:
    //         st.push(abc[i]);
    //         break;
    //     }
    // }


    vector<int> sample = { 1,2,4,5};
    // stack<int> cpSt(sample.begin(), sample.end()); stack can't be copied using this way
    

    auto it  = lower_bound(sample.begin(), sample.end(),3);
    // vector<int>::iterator it;
    cout<<"Lower bound of it "<<*it;
    cout<<"Prev of iterator it "<<*prev(it);

    string str = "abcdefgh";
    cout<<str.substr(0,3);

    string point = ".001";
    cout<<"Pointer 0.001 is "<<stoi(point)<<endl;

}

// when thinking of dp , small recursion problem give ans to small dataset, so every recursive function give result


// https://download.fedsr.us/media/1234821/master.m3u8?token=25bce01609c4497261b2284e02069d3c6d3853cb5c3d634cc49c13b05e99255c&expires=1759141706


// class Solution {
// public:
//     int longestBalanced(string s) {
//         int n = s.size();
//         if(n<3){
//             if(n>0) return 1;
//         }
//         return 0;
//     }

//     map<pair<int,int>,int> state_map;

//     int count_a = 0, count_b =0, count_c =0;
//     int maxLen = 0;

//     state_map[ {0,0}] = -1;

// for(int i=0;i<n;++i){
//     if(s[i]=='a') count_a++;
//     else if(s[i] == 'b') count_b++;
//     else count_c++;

//     pair<int,int> currentState = { count_b - count_a, count_c - count_a};

//     if(stateMap.count(currentState)) maxLen = max(maxLen, i- stateMap[currentState]);
//     else stateMap[currentState] = i;
// }
//     return maxLen;
// };