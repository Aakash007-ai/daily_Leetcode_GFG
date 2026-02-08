#include<bits/stdc++.h>
using namespace std;

/**
 * this is brute force string matching algorithm, where we match as usual
 * for each index of text we run a nested comparison to compare each character
 * 
 * It will give TLE for n = 10^5 and m = 10^5.
 * because 10^5 * 10^5 = 10^10 which is greater than 10^8.
 */

void naiveStringMatchingAlgorithm(string text,string pattern){
    int n = text.size();
    int m = pattern.size();

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            if(text[i+j]!= pattern[j]){
                break;
            }

            if(j == m-1){
                cout<<"Pattern found at "<<i;
            }
        }
    }
}

int main()
{
    string S, P;
    cin >> S >> P;

    naiveStringMatchingAlgorithm(S,P);

    return 0;
}