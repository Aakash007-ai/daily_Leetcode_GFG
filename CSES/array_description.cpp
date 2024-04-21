#include <bits/stdc++.h>
using namespace std;

int ways(vector<int> v, int i, int x, int bound)
{ // i means no. of elements , x means lower bound , bound is upper bound
    printf("ways call with  i=%d , x=%d ,bound=%d\n", i, x, bound);

    // if there is no elements return 0, already traveresed and filled
    if (i == 0 || x == 0) // or if lower bound become out of index we return 0
        return 0;
    if (x > bound) // if lower bound > upper bound
        return 0;

    if (i == 1) // when there is only single elements
    {
        // if first element is equal to upper bound we have reached to end with valid condition

        if (v[i] == x || v[i] == 0) // or we can fill that with any element
        {
            return 1;
        }x
        else
        {
            return 0;
        }
    }

    int ans = 0; // for rest of lower bound >1
    if (v[i] == x || v[i] == 0)
    {
        printf("if condition where v[i]==x || v[i]==0 , v[i] is %d x is %d\n", v[i], x);
        // whn we have that lowerbound == element at that position or we can fill that position
        // solve for one less element with less lower bound , one less with same lower bound , one less with upper lower bound
        ans = ways(v, i - 1, x - 1, bound) + ways(v, i - 1, x, bound) + ways(v, i - 1, x + 1, bound);
    }
    else
    {
        cout << "already filled" << endl;
        return 0;
    }

    return ans;
}

int array_description(int n, int m, vector<int> &v)
{
    int ans = 0;
    for (int i = 1; i < m; i++)
    {
        cout << "iterating from lower bound to upper bound index " << i << endl;
        ans += ways(v, n, i, m);

        printf("ans after iterating over index %d ans we get %d \n", i, ans);
    }
    return ans;
}

// iterating from lower bound to upper bound index 1
// ans after iterating over index 1 ans we get 0
// iterating from lower bound to upper bound index 2
// ans after iterating over index 2 ans we get 3
// iterating from lower bound to upper bound index 3
// ans after iterating over index 3 ans we get 3
// iterating from lower bound to upper bound index 4
// ans after iterating over index 4 ans we get 3
// 3

int main()
{
    int n, m; // take number of array and upper bound
    cin >> n >> m;

    vector<int> arr(n + 1, 0); // a vector with index 1
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << array_description(n, m, arr);
}

// another code help end here

// we have an array, first find 0 part
// traverse only upto that condition if(abs(arr[n-1]-j) >=1) then comapre it with previous , call for next elements ,

// my solution

// int solve(int n, int m, vector<int> arr, int j = 0)
// {
//     //
//     for (int i = j; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             if (i > 0)
//             {
//             }
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> arr(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     cout << array_description(n, m, arr);
// }