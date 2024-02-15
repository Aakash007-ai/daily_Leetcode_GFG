#include <iostream>
#include <unordered_map>

int solution(std::string A, std::string B) {
    int N = A.size();
    int count = 0;

    for (int i = 0; i < N; ++i) {
        std::unordered_map<char, int> freqA, freqB;

        for (int j = 0; i + j < N; ++j) {
            freqA[A[i + j]]++;
            freqB[B[i + j]]++;

            if (freqA == freqB) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    std::string A = "dBacaAA";
    std::string B = "caBdaaA";

    int result = solution(A, B);

    std::cout << "Number of corresponding fragments: " << result << std::endl;

    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;
// #define long long ll;

// void solve2(string a, string b){
//     // O(n^2)
//     int cnt = 0;
//     int n = min(a.size(), b.size());

//     for (int i = 0; i < n; i++){
//         vector <int> f_a(52);
//         vector <int> f_b(52);
//         int equal = 52;
//         for (int j = i; j < n; j++){
//             // int ch1 = mapCharToInt(a[j]);
//             // int ch2 = mapCharToInt(b[j]);
//             int ch1 = int(a[j]);
//             int ch2= int (b[j]);

//             if (f_a[ch1] == f_b[ch1]) equal--;
//             f_a[ch1]++;
//             if (f_a[ch1] == f_b[ch1]) equal++;
//             if (f_a[ch2] == f_b[ch2]) equal--;
//             f_b[ch2]++;
//             if (f_a[ch2] == f_b[ch2]) equal++;
            
//             if (equal == 52) cnt++;
//         }
//     }
//     cout << cnt;
// }

// int main(){
//     solve2("dBacaAA","caBdaaA");
// }