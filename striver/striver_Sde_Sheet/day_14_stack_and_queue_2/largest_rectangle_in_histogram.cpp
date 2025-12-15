#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    vector<int> nextSmallerElement(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n;i>0;i++){
            int curr = heights[i];
            while(st.top()!= -1 && curr>=heights[st.top()]){
                st.pop();
            }
            ans[i-1] = st.top();
            st.push(i-1);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int curr = heights[i];
            while(st.top()!=-1 && curr>=heights[i]){
                st.pop();
            }
            ans[i-1] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights){
        vector<int> nextSmaller = nextSmallerElement(heights);
        vector<int> prevSmaller = prevSmallerElement(heights);
        int n = heights.size();
        int area = 0;
        int ans INT_MIN;
        for(int i=0;i<n;i++){
            if(nextSmaller[i]==-1){
                area = (n-prevSmaller[i]+1)*heights[i];
            }else{
                area = nextSmaller[i]-prevSmaller[i]+1;
            }
            ans = max(ans, area);
        }
        return ans;
    }
};
