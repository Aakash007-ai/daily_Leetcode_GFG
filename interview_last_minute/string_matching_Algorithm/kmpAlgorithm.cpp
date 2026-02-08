#include<bits/stdc++.h>
using namespace std;

/**
 * KMP Algorithm Knuth Morris Algorithm
 * here we create a prefixSuffix array
 * 
 * prefix suffix array means length of particular prefix and suffix
 * means length of repeating prefix 
 * e.g 
 * abab give length 2 as ab is prefix and ab is suffix for index lps[4-1] = 2
 * aaaa give length 3 as lps[4-1] = 3
 * 
 * so it means there must be 2 pointer 1 pointing to current index and another pointing to repeating index len
 */

vector<int> buildLPS(string p){
    int m = p.size();
    // 2 pointer len = 0 , i = 1(since comparison start with next index from start)
    int len = 0;
    int i = 1;

    vector<int> lps(m,0);
    while(i<m){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){// ababc = 00120
                len = lps[len-1]; // going back to 1 index back
            }else{ // abab intial 0 for b 0, again for a
                // 0 if no match
                i++;
            }
        }
    }
    return lps;
}

void kmpAlgorithm(string s, string p){
    int n = s.size();
    int m = p.size();

    int i=0, j=0;
    vector<int> prefixArray = buildLPS(p);

    while(i<n){
        if(s[i]== p[j]){
            i++;
            j++;
        }

        if(j == m){
            cout<<"Pattern found at index "<<i-j;
            j = prefixArray[j-1];// 
        }else if(i<n && s[i]!=p[j]){
            if(j!=0){
                j = prefixArray[j-1];
            }else{
                i++;
            }
        }
    }
}

int main()
{
    string S, P;
    cin >> S >> P;

    kmpAlgorithm(S, P);

    return 0;
}