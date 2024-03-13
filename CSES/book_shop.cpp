#include <bits/stdc++.h>
using namespace std;

int maximumBooks(int n, int x, vector<int> &price, vector<int> &books)
{
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // if (n == 0)
    //     return 0; // if there are no books return 0 as we can buy 0 books
    // if (x == 0)
    //     return 0; // again we have no money to buy books return 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= price[i - 1])
            {
                dp[i][j] = max(books[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][x];

    // if (x >= price[n - 1])
    // {
    //     return max(books[n - 1] + maximumBooks(n - 1, x - price[n - 1], price, books), maximumBooks(n - 1, x, price, books));
    // }
    // return maximumBooks(n - 1, x, price, books);
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n), books(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> books[j];
    }

    cout << maximumBooks(n, x, price, books);
}

// recursion
//  int maximumBooks(int n, int x, vector<int> &price, vector<int> &books)
//  {
//      if (n == 0)
//          return 0; // if there are no books return 0 as we can buy 0 books
//      if (x == 0)
//          return 0; // again we have no money to buy books return 0;

//     if (x >= price[n - 1])
//     {
//         return max(books[n - 1] + maximumBooks(n - 1, x - price[n - 1], price, books), maximumBooks(n - 1, x, price, books));
//     }
//     return maximumBooks(n - 1, x, price, books);
// }
// int main()
// {
//     int n, x;
//     cin >> n >> x;
//     vector<int> price(n), books(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> price[i];
//     }
//     for (int j = 0; j < n; j++)
//     {
//         cin >> books[j];
//     }

//     cout << maximumBooks(n, x, price, books);
// }