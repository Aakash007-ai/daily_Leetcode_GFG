#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    int missing, twice;
	for(int i = 0; i < n; ++i){
        cout<<"\nfor i = "<<i<<endl;
        int targetValue = abs(arr[i]);
        cout<<"targetValue "<<targetValue<<endl;
        if(arr[targetValue - 1] < 0){
            cout<<" arr[targetValue - 1] "<<arr[targetValue-1]<<endl;
            twice = targetValue;
            }
        else{
            cout<<"else\n";
            cout<<"arr[targetValue - 1] "<<arr[targetValue-1]<<endl;
            arr[targetValue - 1] = -arr[targetValue - 1];
            }
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] > 0){
            missing = i + 1;
            break;
        }
    }
    return {missing, twice};
}

int main(){
    vector<int> arr = {1,3,4,5,5};
    auto ans=missingAndRepeating(arr,5);
    cout<<"Missing "<<ans.first<<" Twice "<<ans.second;
}