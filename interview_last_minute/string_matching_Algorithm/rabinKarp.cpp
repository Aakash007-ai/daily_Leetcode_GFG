#include<bits/stdc++.h>
using namespace std;

void rabinKarp(string s, string p){
    int n = s.size();
    int m = p.size();

    int d = 256;
    int hash_p = 0;
    int hash_s = 0;
    int h = 1;
    int q = 101;

    for(int i=1;i<=m-1;i++){// d^0 + d^1 + d^2 .. d^m-1
        h = (h*d)%q;
    }

    // h = d^m-1

    for(int i=0;i<m;i++){
        hash_p = (d*hash_p+ p[i])%q;
        hash_s = (d*hash_s + s[i])%q;
    }

    // hash_p = p[0]*d^m-1 + p[1]*d^m-2 .... + p[m-1]*d^0


    for(int i=0;i<n-m;i++){
        if(hash_p == hash_s){
            int j=0;
            bool match = true;
            while(j<m){
                if(s[i+j] != p[j]){
                    match = false;
                    break;
                }
                j++;
            }
            if(match){
                cout<<"Pattern found at index "<<i<<endl;
            }
        }

        if(i<n-m){
            hash_s = hash_s - s[i]*h;
            hash_s = hash_s*d;
            hash_s = hash_s + s[i+m];
            hash_s = hash_s%q;

            if(hash_s<0) hash_s = (hash_s+q); // for negative results
        }
    }
}