#include<bits/stdc++.h>
using namespace std;

class Solution {
  long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // unordered_map<char,vector<pair<char,int>>a> adjList;
        vector<vector<pair<char,int>>> adjList(26);
        for(int i=0;i<original.size();i++){
            adjList[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }

        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));

        int minCost = 0;

        auto bfs = [&adjList , &minConversionCosts](char s, char t){
            // so we do bfs from s to t , keeping the cost minimum, have to find minimum first
            int cost = 0;
            priority_queue<pair<int,char>, vector<pair<int,char>>, greater<>> pq;
            pq.push({0,s});
            while (!pq.empty()){
                int cost = pq.top().first;
                char node = pq.top().second;

                if(node == t) return cost;
                pq.pop();

                for(auto it: adjList[node]){
                    char nNode = it.first;
                    int nCost = it.second;

                    pq.push({nCost + cost, nNode});
                }
            }
            
        };
        for(int i=0;i<source.size();i++){
            if(source[i]!= target[i]){
                minCost += bfs(source[i], target[i]);
            }
        }
        return minCost;
    }

};


// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         unordered_map<char,vector<pair<char,int>>> adjList;
//         for(int i=0;i<original.size();i++){
//             adjList[original[i]].push_back({changed[i],cost[i]});
//         }
//         int minCost = 0;
//         auto bfs = [&adjList](char s, char t){
//             // so we do bfs from s to t , keeping the cost minimum, have to find minimum first
//             int cost = 0;
//             priority_queue<pair<int,char>, vector<pair<int,char>>, greater<>> pq;
//             pq.push({0,s});
//             while (!pq.empty()){
//                 int cost = pq.top().first;
//                 char node = pq.top().second;
//                 if(node == t) return cost;
//                 pq.pop();
//                 for(auto it: adjList[node]){
//                     char nNode = it.first;
//                     int nCost = it.second;
//                     pq.push({nCost + cost, nNode});
//                 }
//             }       
//         };
//         for(int i=0;i<source.size();i++){
//             if(source[i]!= target[i]){
//                 minCost += bfs(source[i], target[i]);
//             }
//         }
//         return minCost;
//     }
// };