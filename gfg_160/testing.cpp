#include<bits/stdc++.h>
using namespace std;

/*  learning
    for normal array problems
    always think straight forward the common sense and translate that to code

    after writing code dry run on sample case
    dry run on all possible cases u can think

    think about and speak loud about time complexity by iterating over code

    spell about all info about the code and whatever u know about it, what are other approach 

    understand the problem cleary then come up with a algo (e.g. push all zeroes to end think about pattern of non zero)
*/

int main(){
    string in ="12345";
    // cout<<"0123456789
    reverse(in.begin(),in.end());
    cout<<in<<endl;
    reverse(in.begin(),in.begin()+2);
    // reverse(in.begin()+2+1,in.end());
    cout<<in;


    vector<int> arr = { 2,4,1,7,5,0 };
    next_permutation(arr.begin(), arr.end());

}