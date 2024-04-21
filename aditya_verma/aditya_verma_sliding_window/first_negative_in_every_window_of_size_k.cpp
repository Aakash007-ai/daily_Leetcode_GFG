/*
ps -i/p o/p
given an array
12 -1 -7 8 -15 30 16 28
k=3
-1 -1 -7 -15 -15 0
output size n-k+1
find first -ve no. in every window size k

travers over array until we have fixed window size also find -ve int is found

if we have window size == k then push first -ve into ans
increment i,
*/

#include <bits/stdc++.h>
using namespace std;

// k>1
int firstNegative(int n, vector<int> arr, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    int neg = 0;
    while (j < n)
    {
        if (j - i + 1 < k)
        { // window is not formed yet
            if (arr[j] < 0 && neg == 0)
            {
                // assign first negative
                neg = arr[j];
            } // else do nothing
        }

        if (j - i + 1 == k)
        { // at htis index we have ans in neg
            ans.push_back(neg);

            // pushed ans for this window and find next neg
            if(arr[i]==neg){
                //find next neg
                neg=0;
                while(i<j){
                    if(arr[])
                }
            }
            i++;
            //find next neg ,
        }
    }
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