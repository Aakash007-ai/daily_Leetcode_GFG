#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution{
    public:
    static bool comp(pair<double, Item> a, pair<double, Item> b){
        return a.first > b.first;
    }
    double fractionalKanpsack(int W,Item arr[], int n){
        vector<pair<double, Item>> v;
        for(int i=0;i<n;i++){
            double unitPerVolume = (1.0*arr[i].value)/arr[i].weight;
            pair<double, Item> p= make_pair(unitPerVolume,arr[i]);
        }

        sort(v.begin(),v.end(),comp);

        int totalValue  = 0;
        for(int i=0;i<n;i++){
            if(v[i].second.weight > W){
                //we can take fraction value
            }else{
                totalValue += v[i].second.value;
                W -= v[i].second.weight;
            }
        }
    }
};