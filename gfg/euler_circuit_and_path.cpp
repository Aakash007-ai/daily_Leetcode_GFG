#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    //if we have visited all node and last node is starting node return 2
    //if we visited all node and starting and ending node is not same return 1
    //else 0
    int isEulerCircuit(int V, vector<int>adj[]){
	    int odd=0, even=0;
	    for(int i=0;i<V;i++){
	        if(adj[i].size()%2==0) even++;
	        else odd++;
	    }
	    if(even==V) return 2;
	    else if(odd==2) return 1;
	    return 0;
	}
};