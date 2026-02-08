#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        int index = 0;
        while(--n){
            switch(index){
                int top = st.top();
                case 0: // multiplication
                    st.pop();
                    st.push(top*n);
                    break;
                case 1:
                    st.pop();
                    st.push(top/n);
                    break;
                case 2:
                    st.push(n);
                    break;
                case 3:
                    st.push(-n);
                    break;
            }
            index++;
            index%= 4;
        }
        int ans = 0;
        while(!st.empty()){
            ans+= st.top();st.pop();
        }
        return ans;
    }
};