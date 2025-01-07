#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void floyd(vector<vector<int>>&adj,int n){
    for(int x=0;x<n;x++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(u!=v && adj[u][x]!=INT_MAX && adj[x][v]!=INT_MAX && adj[u][v]>adj[u][x]+adj[x][v])
                 adj[u][v]=adj[u][x]+adj[x][v];
            }
        }
    }
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>v(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            int wt=edges[i][2];
            v[x][y]=wt;
            v[y][x]=wt;
        }
        floyd(v,n);
        int node;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int neigh=0;
            cout<<i<<" ";
            for(int j=0;j<n;j++){
                if(v[i][j]<=distanceThreshold){
                    cout<<v[i][j]<<",";
                    neigh++;
                }
            }
            cout<<endl;
            
            if(mini>=neigh){
                mini=min(mini,neigh);
                node=i;
            }
        }
        return node;
    }
};