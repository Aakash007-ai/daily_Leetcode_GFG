// same as kth mallest element but this time we have to
#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq; // min heap smallest element at top
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
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

    cout << kthLargest(arr, k);
}