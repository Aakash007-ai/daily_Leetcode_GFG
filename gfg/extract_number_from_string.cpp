#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long ExtractNumber(string str) {
        string _maxi;
        long long maxi = -1, temp;
        int i = 0, j = 0;
        while(i < str.size()){
            bool t = 0;
            if(str[i] >= '0' && str[i] <= '9'){
                while(i < str.size() && (str[i] >= '0' && str[i] <= '9')){
                    if(str[i] == '9')   t = 1;
                    i++;
                }
                if(!t){
                    _maxi = str.substr(j, i-j);
                    temp = stoll(_maxi);
                    maxi = max(maxi, temp);
                }
            }
            i++;
            j = i;
        }
        return maxi;
    }
};

// class Solution {
//   public:
//     long long ExtractNumber(string sentence) {
//         //first find number then check 9 in it
//         int i=0;
//         int n=sentence.size();
//         long long ans=-1;
//         while(i<n){
//             if(sentence[i] > '0' && sentence[i] < '9'){
//                 int j=i;
//                 bool skip=false;
//                 string st="";
//                 while(sentence[j]!=' ' || j!=n){
//                     if(sentence[j] == '9'){
//                         skip=true;
//                         break;
//                     }
//                     st.push_back(sentence[j]);
//                 }
//                 if(skip){//we got 9 in between so skip it
//                     j++;
//                     j=i;
//                     continue;
//                 }
//                 if(j==n){
//                     long long num=std::stoll(ans,nullptr,10)
//                     ans= max(ans, );
//                 }
//             }
//         }
//     }
// };


int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.ExtractNumber(s);
}