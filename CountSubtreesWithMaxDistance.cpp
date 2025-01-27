#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void floyd(vector<vector<int>> &adj,int n){
    for(int x=0;x<n;x++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(adj[u][x]!=INT_MAX && adj[x][v]!=INT_MAX && adj[u][v]>adj[u][x]+adj[x][v])
                    adj[u][v]=adj[u][x]+adj[x][v];
            }
        }
    }
}
int solve(int num,vector<vector<int>> &adj,int n){
    int node=0,edge=0,maxD=0;
    for(int i=0;i<n;i++){
        if(((num>>i)&1) ==1){
            node++;
            for(int j=i+1;j<n;j++){
                if(((num>>j)&1)==1){
                    if(adj[i][j]==1){
                        edge++;
                    }
                    maxD=max(maxD,adj[i][j]);
                }
            }
        }
    }
    if(node==edge+1)
    return maxD;
    return -1;

}
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1,vector<int>(n+1,INT_MAX));
        int sz=edges.size();
        for(int i=0;i<sz;i++){
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x-1][y-1]=1;
            adj[y-1][x-1]=1;
        }

        floyd(adj,n);
        vector<int>ans(n-1,0);
        for(int i=0;i<(1<<n);i++){
            int cnt=solve(i,adj,n);
            if(cnt>0){
                ans[cnt-1]++;
            }
        }
        return ans;
    }
};