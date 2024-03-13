#include<bits/stdc++.h>
using namespace std;

//learn about comparator and retrun type in comparator >= not work while just > works
//brute force sorting the largest bit number  give error in logic

//so we sort based on the resultant string formed
// a,b
// a will be treated as largest and we retrun true if a+b > b+a
// so in that way number which will be largest will pop out to first

class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
    static bool comp(string a, string b){ //why it give error if i remove static from this comparator function
        // (a+b).compare(b+a);
        return a+b>b+a; //why it give error when i put >= sign for large input
    }

	string printLargest(int n, vector<string> &arr) {
	    // code here
        sort(arr.begin(),arr.end(),comp);
        //now just concat all
        string ans="";
        for(auto it:arr){
            // ans+=it;
            ans.append(it);
            
        }
        return ans;
	}

    //give SISGEV ERROR
    // static bool comp(string a, string b){
    //     string temp1 = a+b;
    //     string temp2 = b+a;
    //     return temp1>=temp2;
    // }

	// string printLargest(int n, vector<string> &arr) {
	//     // code here

    //     sort(arr.begin(),arr.end(),comp);

    //     //now just concat all
    //     string ans="";
    //     for(auto it:arr){
    //         ans+=it;
    //     }
    //     return ans;
	// }
};

int main(){
    int n,i;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    auto ans = obj.printLargest(n,arr);
    cout<<ans;
}