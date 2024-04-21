#include <bits/stdc++.h>
using namespace std;

// nearly sorted means
//  element at index i  in sorted array can be on i, i-1 or i+1 in original array
//  5 10 30 20 40

// trick is that in normal sorted array we find index only at mid but here we find at mid-1 and mid+1 too