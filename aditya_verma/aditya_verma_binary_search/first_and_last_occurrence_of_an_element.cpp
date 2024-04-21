#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> arr, int k)
{
    int s = 0, e = arr.size() - 1;
    int result = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == k)
        {
            // we have find first element
            result = mid;
            e = mid - 1; // to find first occurence
            // s=mid+1; //to find last occurence
        }
        else if (arr[mid] > k)
        {
            // searchig space is left side
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    if (result == -1)
        return -1;
    if (result == s || result == e)
        return s; // or return e
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
    // binarySearch(arr, k);
}