#include<bits/stdc++.h>
using namespace std;

int main(){
    // program to print ASCII value of 0 to 9
    for(int i=0;i<=9;i++){
        cout<<"ASCII value of "<<i<<" is "<<i+48<<endl;
    }
    cout<<'0'+1<<"\n"; // it will print 49 as '0' is turned to 48 + 1 is 49
    cout<< char('0'+5)<<endl;
    cout<< char('a'+5)<<endl;
    cout<<"\n";
     string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<str.length();i++){
        cout<<"ASCII value of "<<str[i]<<" is "<<(int)str[i]<<endl;
    }
    
}