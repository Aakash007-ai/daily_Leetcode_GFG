#include<bits/stdc++.h>
using namespace std;


// Input: arr = [4, 8, 5, 2, 25]
// Output: [2, 5, 2, -1, -1]

// Input: arr = [10, 9, 8, 7]
// Output: [9, 8, 7, -1]
class Solution {
public:

    vector<int> nextSmallerElements(const vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();
        vector<int> ans(n);

        for(int i=n;i>0;i--){
            int curr = arr[i-1];
            while(st.top()>= curr){
                st.pop();
            }
            ans[i-1] = st.top();
            st.push(arr[i-1]);
        }
        return ans;
    }
};
