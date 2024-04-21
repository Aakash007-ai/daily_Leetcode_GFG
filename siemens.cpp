#include <iostream>
#include <vector>
using namespace std;

void performQueries(vector<int>& arr, vector<pair<long long, int>>& queries) {
    vector<int> ans;
    int n = static_cast<int>(arr.size()) - 1;
    int q = static_cast<int>(queries.size());

    for (int i = 0; i < q; ++i) {
        long long t = queries[i].first;
        int m = queries[i].second;

        if (m > n) {
            ans.push_back(-1);
            continue;
        }

        int turn = t / n;
        int rem = t % n;

        if (rem == 0 && turn % 2 == 1) {
            ans.push_back(-1);
            continue;
        }

        if (rem == 0 && turn % 2 == 0) {
            ans.push_back(arr[m]);
            continue;
        }

        if (turn % 2 == 0) {
            int cursize = n - rem;
            if (cursize < m) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(arr[m + rem]);
        } else {
            int cursize = rem;
            if (cursize < m) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(arr[m]);
        }
    }

    for (int i : ans) {
        cout << i << "\n";
    }
}

int main() {
    vector<int> arr = { 1,2,3,4,5};
    vector<pair<long long, int>> queries = {
        { 1,4 },
        { 2,1 },
        { 9,4 },{4,2},{21,1}
    };

    performQueries(arr, queries);

    return 0;
}



// #include <iostream>
// #include <vector>

// std::vector<int> solve(int N, std::vector<int>& initialArrangement, int Q, std::vector<std::pair<int, int>>& queries) {
//     std::vector<int> result;

//     // Create an array to store the current arrangement
//     std::vector<int> currentArrangement(N);
//     for (int i = 0; i < N; ++i)
//         currentArrangement[i] = initialArrangement[i];

//     // Process each query
//     for (int i = 0; i < Q; ++i) {
//         int t = queries[i].first; // Time
//         int M = queries[i].second; // Mth element

//         // Calculate the position of the Mth element at time t
//         int position = (M + t - 1) % N;
//         result.push_back(currentArrangement[position]);
//     }

//     return result;
// }

// int main() {
//     int N, Q;
//     std::cin >> N;
//     std::vector<int> initialArrangement(N);
//     for (int i = 0; i < N; ++i)
//         std::cin >> initialArrangement[i];

//     std::cin >> Q;
//     std::vector<std::pair<int, int>> queries(Q);
//     for (int i = 0; i < Q; ++i)
//         std::cin >> queries[i].first >> queries[i].second;

//     std::vector<int> output = solve(N, initialArrangement, Q, queries);
//     for (int val : output)
//         std::cout << val << " ";

//     return 0;
// }
















// #include <iostream>
// #include <vector>

// std::vector<int> solve(int N, std::vector<int>& initialArrangement, int Q, std::vector<std::pair<int, int>>& queries) {
//     std::vector<int> result;

//     // Create an array to store the current arrangement
//     std::vector<int> currentArrangement(N);
//     for (int i = 0; i < N; ++i)
//         currentArrangement[i] = initialArrangement[i];

//     // Process each query
//     for (int i = 0; i < Q; ++i) {
//         int t = queries[i].first; // Time
//         int M = queries[i].second; // Mth element

//         // Calculate the position of the Mth element at time t
//         int position = (M + t - 1) % N;
//         result.push_back(currentArrangement[position]);
//     }

//     return result;
// }

// int main() {
//     int N, Q;
//     std::cin >> N;
//     std::vector<int> initialArrangement(N);
//     for (int i = 0; i < N; ++i)
//         std::cin >> initialArrangement[i];

//     std::cin >> Q;
//     std::vector<std::pair<int, int>> queries(Q);
//     for (int i = 0; i < Q; ++i)
//         std::cin >> queries[i].first >> queries[i].second;

//     std::vector<int> output = solve(N, initialArrangement, Q, queries);
//     for (int val : output)
//         std::cout << val << "\n";

//     return 0;
// }
