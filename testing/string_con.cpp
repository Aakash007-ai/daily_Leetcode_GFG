#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;



int main(){
    string s;
    cin>>s; 
    // cout<<"input string is "<<s<<endl;
    // string cpy=s; //(s.begin(),s.end());
    // cout<<"copy strinig is "<<cpy;
    string ans="";

    for(auto it:s){
        if(!isalpha(it)){
            string cpy=ans;//(ans.begin(),ans.end());
            for(int i=0;i<it-48;i++){
                ans+=cpy;
            }
        }
        else{
            //cout<<it<<endl;
            // cout<<typeid(it).name()<<endl;
            ans.push_back(it);
        }
    }
    //ans=s.append(cpy);
    
    cout<<"\n Res string is "<<ans<<endl;
}