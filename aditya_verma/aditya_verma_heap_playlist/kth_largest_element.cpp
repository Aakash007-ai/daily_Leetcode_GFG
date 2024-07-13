// same as kth mallest element but this time we have to
#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq; // min heap smallest element at top when pop
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
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pq.push(arr[i]);

    }
    int k;
    cin >> k;

    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }

    cout << kthLargest(arr, k);
}