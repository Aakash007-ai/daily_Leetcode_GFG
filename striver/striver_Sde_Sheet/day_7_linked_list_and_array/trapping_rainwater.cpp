// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int ans = 0;
//         vector<int> suffixMax(n+1,0);
//         for(int i=n-1;i>=0;i--){
//             suffixMax[i] = max(height[i],suffixMax[i+1]);
//         }

//         int prefixMax = height[0];
//         for(int i=1;i<n;i++){
//             int minHeight = min(prefixMax, suffixMax[i]);
//             if(minHeight >= height[i]){
//                 ans += (minHeight-height[i]);
//             }

//             prefixMax = max(prefixMax,height[i]);
//         }
//         return ans;
//     }
// };