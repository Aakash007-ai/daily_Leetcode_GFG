#include<bits/stdc++.h>
using namespace std;

//brute approach
/*
    iterate j over A and then for each i in B do V.PUSH_BACK(A[i]+B[j]) THEN FINALLY SORT V;
    O(n*n) + O(nLogn) gives o(n^2) not appropriate
    if i sort it o(nlogn)
    then use algo such that it never iterate over n*n

*/

class Solution {
  public:
    //o(nlogn) :- time (nlog n is sorting)
    //o(n) space
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        int i=A.size()-1;
        int j=B.size()-1;
        vector<int> ans;
        priority_queue<int> q;
        while(K--){
            if(i==j){
                
                q.push(A[i]+B[j]);
                continue;
            }

            
        }
    }

    
};


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> A(n),B(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    Solution obj;
    cout<<obj.maxCombinations(n,k,A,B);
}