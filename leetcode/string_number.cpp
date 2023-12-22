#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;


int main(){
    string s="123456";
    // cout<<type_name<decltype(s)>();
    cout<<s[2]<<" "<<typeid(int(s[2])).name()<<" "<<int(s[4]);
}
