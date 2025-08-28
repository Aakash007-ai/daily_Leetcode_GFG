#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     int knapsack(int W,int wt[], int val[],int n){
//         if(n==0 || W==0) return 0; // if there are no elemennts return profit 0
//         //also if weight is 0 , means we can't pick anything from bag since capacity is 0

//         if(W-wt[n-1]>=0){//condition when we can pick that element
//             return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W, wt,val,n-1));
//         }
//         return knapsack(W, wt,val,n-1);
//     }
// };

// int main (){
//     int n;cin>>n;
//     int itemWeight[n];
//     int itemPrice[n];
//     for(int i=0;i<n;i++){
//         cin>>itemWeight[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>itemPrice[i];
//     }
//     int W;cin>>W;
//     Solution obj;
//     cout<<obj.knapsack(W,itemWeight,itemPrice,n);
// }


//memoization or bottom up
//for memoization we first code recurison
// check what is changing for every recursion call
// here n and weight is changing
// so we have to store them and for a particular we have to memoize the value

// class Solution {
// public:
//     int** dp; // Pointer to pointer for dynamic 2D array

//     void initDP(int n, int W) {
//         dp = new int*[n + 1];          // Allocate rows
//         for (int i = 0; i <= n; ++i) {
//             dp[i] = new int[W + 1];    // Allocate columns
//             for (int j = 0; j <= W; ++j) {
//                 dp[i][j] = -1;         // Initialize with -1
//             }
//         }
//     }

//     int knapsack(int W, int wt[], int val[], int n) {
//         if (n == 0 || W == 0) return 0;

//         if (dp[n][W] != -1) return dp[n][W];

//         if (W - wt[n - 1] >= 0) {
//             return dp[n][W] = max(
//                 val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
//                 knapsack(W, wt, val, n - 1)
//             );
//         }

//         return dp[n][W] = knapsack(W, wt, val, n - 1);
//     }

//     void freeDP(int n) {
//         for (int i = 0; i <= n; ++i)
//             delete[] dp[i];
//         delete[] dp;
//     }
// };

// int main() {
//     int n;
//     cin >> n;
//     int* itemWeight = new int[n];
//     int* itemPrice = new int[n];

//     for (int i = 0; i < n; i++) cin >> itemWeight[i];
//     for (int i = 0; i < n; i++) cin >> itemPrice[i];

//     int W;
//     cin >> W;

//     Solution obj;
//     obj.initDP(n, W);
//     cout << obj.knapsack(W, itemWeight, itemPrice, n) << endl;
//     obj.freeDP(n); // Clean up

//     delete[] itemWeight;
//     delete[] itemPrice;

//     return 0;
// }

//using vector
// class Solution {
// public:
//     vector<vector<int>> dp;

//     int knapsack(int W, int wt[], int val[], int n) {
//         if (n == 0 || W == 0) return 0;

//         if (dp[n][W] != -1) return dp[n][W];

//         if (W - wt[n - 1] >= 0) {
//             return dp[n][W] = max(
//                 val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
//                 knapsack(W, wt, val, n - 1)
//             );
//         }

//         return dp[n][W] = knapsack(W, wt, val, n - 1);
//     }

//     void initializeDP(int n, int W) {
//         dp.assign(n + 1, vector<int>(W + 1, -1)); // Resize and initialize with -1
//     }
// };

// int main() {
//     int n;
//     cin >> n;
//     int itemWeight[n];
//     int itemPrice[n];

//     for (int i = 0; i < n; i++) cin >> itemWeight[i];
//     for (int i = 0; i < n; i++) cin >> itemPrice[i];

//     int W;
//     cin >> W;

//     Solution obj;
//     obj.initializeDP(n, W);

//     cout << obj.knapsack(W, itemWeight, itemPrice, n);
// }




// top down
class Solution {
public:

    int knapsack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // Initialize dp with -1

        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(j>=wt[i-1]){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

       return dp[n][W];
    }
};

int main() {
    int n;
    cin >> n;
    int itemWeight[n];
    int itemPrice[n];

    for (int i = 0; i < n; i++) cin >> itemWeight[i];
    for (int i = 0; i < n; i++) cin >> itemPrice[i];

    int W;
    cin >> W;

    Solution obj;

    cout << obj.knapsack(W, itemWeight, itemPrice, n);
}
