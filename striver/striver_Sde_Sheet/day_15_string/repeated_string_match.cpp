#include<bits/stdc++.h>
using namespace std;

/**
 * brute force first store all matched string, use vector/ stack
 */
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        vector<int> repeatedIdx;
        int bN = b.size();
        int aN = a.size();
        if(bN == 0) return 0;
        if(bN < aN) return -1;

        /// find all repeated points matching to first index;
        for(int i=0;i<aN;i++){
            if(a[i]== b[0]) repeatedIdx.push_back(i);
        }

        for(int i=0;i<repeatedIdx.size();i++){
            int j= 0, k=repeatedIdx[i];
            int cnt = 1;
            while(j<bN && a[k%aN] == b[j]){
                if(k%aN == 0) cnt++;
                j++;k++;
            }

            if(j == bN) return cnt;
        }
        return -1;
    }
};


 int Rabin_Karp(string s1, string s2) 
    {
        long long m=s1.size();
        long long n=s2.size();
        
        long long p = 31;
        long long pow = 1;
        long long mod = 1e9+7;
        long long targetHashVal = 0;
        
        // targetHashVal - calculate hash value of pattern
        for(long long i=0;i<n;i++){
            targetHashVal = (targetHashVal + (s2[i]-'a'+1)*pow)%mod;
            pow = (pow*p)%mod;
        }
        
        // Rabin-Karp algo :
        // prefix hash array
        vector<long long>pha(m);
        // power array : so that my time is not wasting in calculating big powers
        vector<long long>pa(m);
        
        pha[0] = s1[0]-'a'+1;
        pa[0] = 1;
        pow = p;
        
        for(long long i=1;i<m;i++){
            pha[i] = (pha[i-1] + (s1[i]-'a'+1)*pow)%mod;
            pa[i] = pow;
            pow = (pow*p)%mod;
        }
        
        //Now Start sliding window
        // initialize variables for the starting and ending points of window
        long long sp = 0, ep = n-1;
        
        while(ep < m)
        {
            long long win = pha[ep];
            if(sp>0)
                win = (win - pha[sp-1]+mod)%mod; // agar value negative hoti hai toh usme bas mod add kardo
            
            if(win == (targetHashVal*pa[sp])%mod){
                return 1;
            }
            sp++,ep++;
        }
        return 0;
    }