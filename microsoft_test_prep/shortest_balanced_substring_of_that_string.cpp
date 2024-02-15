#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkBalanced(string& s, int start, int end) {
        unordered_set<char> chars;
        for (int i=start; i <= end; i++) {
            chars.insert(s[i]);
        }
        for (auto& c : chars) {
            if (c >= 'a' && c <= 'z') {
                if (chars.count(c-32) == 0) return false;
            } else if (c >= 'A' && c <= 'Z') {
                if (chars.count(c+32) == 0) return false;
            }
        }
        return true;
    }
public:
    string shortestBalancedSubstr(string s) { // 'bB'
        for (int len=2; len <= s.size(); len++) {
            for (int i=0; i <= s.size()-len; i++) {
                bool check = checkBalanced(s, i, i+len-1);
                if (check) {
                    return s.substr(i,len);
                }
            }
        }
        return "-1";
    }
};

int main() {
    Solution s;
    cout << s.shortestBalancedSubstr("bB") << endl;
    cout << s.shortestBalancedSubstr("CATattac") << endl;
    cout << s.shortestBalancedSubstr("azABaabza") << endl;
    cout << s.shortestBalancedSubstr("TacoCat") << endl;
    cout << s.shortestBalancedSubstr("AcZCbaBz") << endl;
    cout << s.shortestBalancedSubstr("Madam") << endl;
}