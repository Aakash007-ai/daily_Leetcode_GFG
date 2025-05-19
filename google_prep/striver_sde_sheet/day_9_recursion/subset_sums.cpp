#include <bits/stdc++.h>
using namespace std;

void subsetSumsHelper(int index, int currentSum, vector<int>& arr, vector<int>& result) {
    if (index == arr.size()) {
        result.push_back(currentSum);
        return;
    }

    // Include current element
    subsetSumsHelper(index + 1, currentSum + arr[index], arr, result);

    // Exclude current element
    subsetSumsHelper(index + 1, currentSum, arr, result);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int> result;
    subsetSumsHelper(0, 0, arr, result);
    sort(result.begin(), result.end());  // Sort in increasing order
    return result;
}

int main() {
    vector<int> arr = {2, 3};
    vector<int> result = subsetSums(arr);

    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
