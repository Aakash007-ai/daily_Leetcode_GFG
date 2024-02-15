#include<bits/stdc++.h>
using namespace std;

void mergeArraysInPlace(std::vector<int>& arr) {
    int n = arr.size() / 2;

    for (int i = 2 * n - 2; i > 0; i -= 2) {
        // Perform a cyclic rotation on the elements between index i and i-n
        int temp = arr[i];
        arr[i] = arr[i - n];
        arr[i - n] = temp;
    }
}

int main() {
    // Example usage:
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    mergeArraysInPlace(arr);

    // Print the result
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
