#include<bits/stdc++.h>
using namespace std;


//check constraints and assume alog time complexity

//think of brute force then optimize that shit (check repetitive work we are performing)

//always first assume example and 
//run your assumed algo with dry run 
// along with that make algo
// assume base case too and make nbase cases from that



//think loud and code according to that

int main(){
    vector<int> arr= {6,3,5,5,2,4,5,4,6,7,6,8};
    cout<<"Size of array is ----"<<arr.size()<<endl;
    sort(arr.begin()+3,arr.end());
    for(auto it:arr){
        cout<<it<<" ";
    }


    vector<vector<int>> v(arr.size()); //how does it behave
    cout<<"first element of vector is---"<<v[0].size(); //means no element is in first vector


    //check comparator or proirity queue max heap or min heap



    //vector<vector<int>> ans;
    // ans.back() //give us last vector



    int n=6,m=3;
    int sol=m-- + n-- -1;
    cout<<"\n"<<sol;
}