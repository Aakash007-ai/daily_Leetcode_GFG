#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * we have a vector population representing population in a city 
 * and a binary string of size of cities representing security, 
 * 
 * security can move left by 1 only 0th security can't move
 * 
 * 
 * population = [5, 4, 5, 1]
 * unit        = "0111"
 */

ll moveUnits(vector<int>& pop, string unit){
    int n = pop.size();
    ll prev0 = 0;
    ll prev1 = INT_MIN;

    for(int i=0;i<n;i++){
        ll curr0 = max(prev0,prev1);
        ll curr1 = INT_MIN;
        
        if(unit[i]=='1'){
            curr1 = max(prev0, prev1) + pop[i];

            if(i>0){
                curr0 = max(prev0+(ll)pop[i-1], curr0);
            }
        }

        prev0 = curr0;
        prev1 = curr1;
    }
    return max(prev0,prev1);
}


int main(){
    int n;
    cin>>n;
    vector<int> population(n);
    for(int i=0;i<n;i++){
        cin>>population[i];
    }
    string security;
    cin>>security;
}