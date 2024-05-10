// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n + 1, 0);

//     for (int i = 1; i * i <= n; i++) {
//         arr[i * i] = 1;
//     }

//     for (int i = 1; i <= n; i++) {
//         cout << arr[i];
//     }

//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<bool> arr(n+1, true); // Initialize all elements to true

    for(int i = 2; i*i <= n; i++){
        if(arr[i]){ // If i is prime
            for(int j = i*i; j <= n; j += i){
                arr[j] = !arr[j]; // Toggle multiples of i
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << arr[i];
    }

    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;cin>>n;
//     vector<int> arr(n+1,0);
//     for(int i=1;i<=n;i++){
//         for(int j=i;j<=n;j+=i){
//             arr[j]=!arr[j];
//             // cout<<arr[j];
//         }
//     }
//     for(int i=1;i<=n;i++){
//         cout<<arr[i];
//     }
//     //optimisez this code
// }