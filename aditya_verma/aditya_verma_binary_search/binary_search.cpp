#include <bits/stdc++.h>
using namespace std;

// we are given array is sorted and we have to find at what index an element occur

// brute force we do a linear search but what is the use of being a sorted

/*
    binary search
    so in binary search we know array is sorted so we use that thing and narrow down our search area
    so initially we check whether mid element is greater or smaller
    so if element is smaller than mid we search in first mid half
    if element is greater then we search in next half

    e.g. 1 2 3 4 5 6 7 8 9
    k=3
    l=0 , end =9 , mid =9/2 =4 //end will be size of array or our index , let's assume size of array

    arr[4]=5
    l=0 , end = mid or mid -1
    let's


*/
// int binarySearch(vector<int> arr, int k)
// { //if all elements are distinct it gives us that index and it is there
//     int s = 0, n = arr.size(), e = n - 1;
//     while (s <= e)
//     {
//         int mid = (s + e) / 2;
//         if (arr[mid] == k)
//             return mid;
//         else if (arr[mid] < k)
//             s = mid + 1;
//         else
//             e = mid - 1;
//     }
//     return s;
// }

/////---------------------------learing----------------------
/*
    think of optimized approach and code according to that
    think of index s=0, e = size-1 ,mid =(s+e)/2 , use s=mid-1 or e=mid+1

    for s==e => mid=s single element there
    also have to calculate that
    so while(s<=e){

    }

    whatever we want visualise that as tree how we go through it,
    according to constraints and requirements modify inbetween code

    to avoid overflow we use mid = s + (e-start)/2


    think of searching space and where to move according to condition

*/

int binarySearch(vector<int> arr, int k)
{

    int s = 0, n = arr.size(), e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] >= k)
            e = mid - 1;
        else
            s = mid + 1;
    }

    cout << "s = " << s << " e = " << e;

    return s;
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
    binarySearch(arr, k);
}