#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestPath(vector<vector<long long>> &adj){
           for(int x=0;x<26;x++){
            for(int u=0;u<26;u++){
                for(int v=0;v<26;v++){
                    if(adj[u][x]!=INT_MAX && adj[x][v]!=INT_MAX && adj[u][v]>adj[u][x]+adj[x][v])
                        adj[u][v]=adj[u][x]+adj[x][v];
                }
            }
           }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=source.size();
        int m=original.size();
        long long sum=0;
        vector<vector<long long>> adj(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<m;i++){
            // cout<<original[i]<<" "<<cost[i]<<endl;
            adj[original[i]-'a'][changed[i]-'a']=min((long long)cost[i],adj[original[i]-'a'][changed[i]-'a']);
        }
        shortestPath(adj);
        for(int i=0;i<n;i++){
            if(source[i]!=target[i]){
                long long len=adj[source[i]-'a'][target[i]-'a'];
                if(len==INT_MAX)
                return -1;
                sum+=len;
            }
        }
        return sum;
    }
};