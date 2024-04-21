#include <bits/stdc++.h>
using namespace std;

// n=5 0 based index
// 0 1 1 2 3 5
// 0 1 2 3 4 5
// 0 1
class Solution
{
public:
    vector<int> Series(int n)
    {
        if (n == 1)
            return {0, 1};
        // Code here
        vector<int> ans(n + 1);
        ans[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<int> ans = obj.Series(n);
}