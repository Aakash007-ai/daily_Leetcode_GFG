#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {

    }
};



// brute force
// Z fucntion
// KMP algo
// Rabin Karp
// class Solution {
//     public:
// }

/**
 * brute force 
 *  iterate over string then find pattern using nested loop
 *  for i=0;i < s.length(); i++
 *      while(j<m && s[k++] = s[j++]){}
 *        if j==m return i// returning first matched idx; 
 *  
 * time complexity o(n^2)
 */

 /**
  * Rabin Karp , rolling hash 
  * create a target hash using hash function either by p[0]*p^0 + p[1]*p^1... P[n-1]*p^n-1;
  * 
  * then 2 array , prefixHash, prefixPow
  * create window 0 to n-1, calcuate has for this window, prefixHas[i] prefixHash[i-n+1];
  * if(hashWindow == targetHash * prefixArr[i-n]) then match by characters
  *    
  */

  /**
   * KMP , Knuth Morris Pattern 
   * we have to create LPS , longest prefix , suffix array
   * LPS[i]  means length of longest prefix end
   */