#include<bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin >> x;
    int i = 0;
    unordered_map<char, int> mp;
    for (auto it : x) {
        auto itr=mp.find(it);
        // unordered_map<char, int>::iterator itr = mp.find(it);
        if (itr != mp.end()) {
            cout << itr->second; // Use ->first instead of .first
        } else {
            mp[it] = i;
        }
        i++;
    }
}