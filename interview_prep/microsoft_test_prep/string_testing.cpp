#include<bits/stdc++.h>
using namespace std;

int main(){
    //erassing
    string str= "geeksForgeeks";
    

    //to erase a particular character pass its poition
    auto it=str.find('o'); //give index
    cout<<"Index value and pointer index is :::---"<<it<<endl;
    str.erase(str.begin()+it);
    cout<<"erased charcter from string "<<str<<endl;

















    // //find :- is used to find the first occurences of the substr in parent string
    // // The function returns the index of the first occurrence of the sub-string.
    // // If the sub-string is not found it returns string::npos(string::pos is a static member with its value as the highest possible for the size_t data type).
    // string str = "geeksforgeeks a computer science";
    // string str1 = "geeks";

    // // Find first occurrence of "geeks"
    // size_t found = str.find(str1);
    // if (found != string::npos)
    //     cout << "First occurrence is " << found << endl;

    // Find next occurrence of "geeks".
    // size_t found = str.find(str1, found+1);
    // if (found != string::npos)
    //     cout << "Next occurrence is " << found << endl;


    //search for partial string of child in parent string
    // size_t find (const char *str, size_t pos, size_t n); 
    // size_t found = str.find("geeks.practice", 0, 5);
    // if (found != string::npos)
    //     cout << found << endl;

    





    

    // //resizing strings
    // string geeeks = "GeeksforGeeks";
    // cout<<"Length of string "<<geeeks.length()<<endl;
    // cout<<"Size of length  "<<geeeks.size()<<endl;
    // geeeks.resize(5);
    // cout<<"Resized decreased geeks  "<<geeeks<<endl;
    // geeeks.resize(8);// '\0' add spaces in increased
    // cout<<"Resize increased geeks "<<geeeks<<endl;
    // geeeks.resize(10,'A');
    // cout<<"Resized increas with char A geeks "<<geeeks<<endl;

    
}