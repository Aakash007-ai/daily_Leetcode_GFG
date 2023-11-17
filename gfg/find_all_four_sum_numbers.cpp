#include<bits/stdc++.h>
using namespace std;

//brute force o(n*n*n*n)
/*
    for(i=0;i<n-3;i++){
        for(j=i+1;j<n-2;j++){
            for(k=j+;j<n-1;k++){
                for(l=k+1;l<n;l++)
                arr[i]+arr[j]+arr[k]+arr[l]==sum ? save answer :continue;
            }
        }
    }
*/

/*Optimised approach dp
*/

/*  think of 2 sum using 2 pointer approach 
    we sort array and then move 2 pointerfrom last and end 
    while(j>i)
    if(arr[i]+arr[j] == sum) ans
    if(arr[i]+arr[j] > sum) j--; else i++
*/

/* 4 sum 
    fix 2 index then jump for others 
    optimising brute force
    for(int i=0;i<n;i++){
        for(int j=i+1;j++){
            now 2 sum
        }
    }
*/




class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    //hack is we have to ans unique combintions
    vector<vector<int> > fourSum(vector<int> &a, int K) {
        // Your code goes here
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && a[i]==a[i-1])continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && a[j]==a[j-1])continue;
                int s,k=j+1,l=n-1;
                while(k<l)
                {
                    s=a[i]+a[j]+a[k]+a[l];
                    if(s==K)
                    {
                        
                        vector<int> v={a[i],a[j],a[k],a[l]};
                        ans.push_back(v);
                        k++;l--;
                        while(k<l && a[k]==a[k-1])k++;
                        while(k<l && a[l]==a[l+1])l--;
                    }
                    else if(s<K)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }




    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        //0 0 1 1 2
        //0 1 2 3 4 n=5
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();

        for(int i=0;i<n;i++){
            /*don't worry whether to choose n-3 nor n-2 just first build basic algo
            as it will be eliminated later by default in consecutive conditions
            */
           if(i>0 && arr[i]==arr[i-1])continue; //what if prev element is equal to next element skip it
            for(int j=i+1;j<=n-2;j++){
                if(i>0 && arr[j]==arr[j-1])continue; //what we can choose next elementbut we can't choose same element
            
                int sum,st=j+1,en=n-1;

                while(en>st){
                    sum=arr[i]+arr[j]+arr[st]+arr[en];
                    if(sum == k){
                        ans.push_back({arr[i],arr[j],arr[st],arr[en]});
                        en--;
                        st++;
                        while(st<en && arr[st]==arr[st-1]) st++;
                        while(st<en && arr[en]==arr[en+1]) en--; 
                    }
                    else if(sum<k){
                        st++;
                    }
                    else en--;
                }
            }
        }
        return ans;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    vector<vector<int>> ans = obj.fourSum(arr,k);
    for(auto &it:ans){
        for(auto &itr : it){
            cout<<itr<<" ";
        }
        cout<<endl;
    }

    if(ans.empty()){
        cout<<-1;
    }
    return 0;
}