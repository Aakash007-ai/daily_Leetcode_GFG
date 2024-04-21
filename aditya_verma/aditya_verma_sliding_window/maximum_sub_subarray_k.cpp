/*
identification
ps ip o/p
code

i.p arr size 7
arr = 2 5 1 8 2 9 1
window size k = 3


window size is given
asking for sub array
so fixed sized sliding window
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int n, vector<int> v, int k)
{
    int i = 0, j = 0;
    int wSum = 0;
    int ans = INT_MIN;
    while (j < n)
    {
        // if(j-i+1<k){
        //     //window size is less increase it

        // }

        // add j sum
        wSum += v[j];

        if (j - i + 1 == k)
        {
            ans = max(ans, wSum);
            // increase j and i
            wSum -= v[i++];
            j++;
        }
        else if (j - i + 1 < k)
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << maxSubArray(n, arr, k);
}
