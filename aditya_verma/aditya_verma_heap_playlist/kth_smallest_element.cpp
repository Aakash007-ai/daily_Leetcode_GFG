#include <bits/stdc++.h>
using namespace std;

// in interview first start with sorting then use priority queue
// as TC of sorting o(nlogn) changes to o(nlogk)
int kthSmallest(vector<int> arr, int k)
{

    priority_queue<int> pq; // max heap by default so that smallest kth element always there
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
}